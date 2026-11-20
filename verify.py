#!/usr/bin/env python3
"""Compile and verify reviewed BOJ solutions; build products stay in a temporary directory."""

import argparse
import functools
import itertools
import math
import os
from pathlib import Path
import random
import shlex
import subprocess
import tempfile


ROOT = Path(__file__).resolve().parent
PROBLEMS = (1005, 1006, 1007, 1016, 1017, 1018, 1019, 1021, 1022, 1024,
            1026, 1028, 1029, 1037, 1043, 1057, 1058, 1069, 1072, 1074)


class Solution:
    def __init__(self, problem, executable):
        self.problem = problem
        self.executable = executable
        self.cases = 0

    def run(self, data):
        result = subprocess.run(
            [str(self.executable)], input=data, capture_output=True, text=True,
            timeout=10,
        )
        if result.returncode != 0:
            raise RuntimeError(
                f"BOJ {self.problem}: exit {result.returncode}, input={data[:500]!r}\n"
                f"{result.stderr}"
            )
        return result.stdout

    def expect(self, data, expected, cases=1):
        actual = self.run(data).split()
        expected = [str(value) for value in expected]
        if actual != expected:
            raise AssertionError(
                f"BOJ {self.problem}: input={data[:500]!r}\n"
                f"expected={expected[:30]}\nactual={actual[:30]}"
            )
        self.cases += cases


def check_1005(solution, rng):
    inputs, expected = [], []
    for _ in range(150):
        n = rng.randint(1, 20)
        order = rng.sample(range(n), n)
        times = [rng.randint(0, 100) for _ in range(n)]
        edges = [(order[i], order[j]) for i in range(n) for j in range(i + 1, n)
                 if rng.random() < 0.25]
        finish = times[:]
        for node in order:
            finish[node] = times[node] + max(
                [finish[a] for a, b in edges if b == node] + [0]
            )
        target = rng.randrange(n)
        inputs.append(f"{n} {len(edges)}\n" + " ".join(map(str, times)) + "\n"
                      + "".join(f"{a + 1} {b + 1}\n" for a, b in edges)
                      + f"{target + 1}\n")
        expected.append(finish[target])
    # Maximum-depth dependency chain, then a smaller case to check state reset.
    inputs += ["1000 999\n" + "100000 " * 1000 + "\n"
               + "".join(f"{i} {i + 1}\n" for i in range(1, 1000)) + "1000\n",
               "1 0\n0\n1\n"]
    expected += [100000000, 0]
    solution.expect(f"{len(inputs)}\n" + "".join(inputs), expected, len(inputs))


def minimum_cover(values, capacity):
    n = len(values) // 2
    neighbors = [set() for _ in values]
    for i in range(2 * n):
        row, column = divmod(i, n)
        for j in ((1 - row) * n + column, row * n + (column + 1) % n,
                  row * n + (column - 1) % n):
            if i != j and values[i] + values[j] <= capacity:
                neighbors[i].add(j)

    @functools.lru_cache(None)
    def cover(mask):
        if not mask:
            return 0
        first = (mask & -mask).bit_length() - 1
        rest = mask ^ (1 << first)
        return 1 + min([cover(rest)] + [cover(rest ^ (1 << j))
                                      for j in neighbors[first] if rest >> j & 1])

    return cover((1 << (2 * n)) - 1)


def check_1006(solution, rng):
    tests = []
    for n in range(1, 5):
        tests += [(list(values), 2) for values in itertools.product((1, 2), repeat=2 * n)]
    for n in range(1, 8):
        for _ in range(80):
            capacity = rng.randint(1, 12)
            tests.append(([rng.randint(1, capacity) for _ in range(2 * n)], capacity))
    inputs, expected = [], []
    for values, capacity in tests:
        n = len(values) // 2
        inputs.append(f"{n} {capacity}\n" + " ".join(map(str, values[:n])) + "\n"
                      + " ".join(map(str, values[n:])) + "\n")
        expected.append(minimum_cover(values, capacity))
    for capacity, answer in ((1, 20000), (2, 10000)):
        inputs.append(f"10000 {capacity}\n" + "1 " * 10000 + "\n" + "1 " * 10000 + "\n")
        expected.append(answer)
    solution.expect(f"{len(inputs)}\n" + "".join(inputs), expected, len(inputs))


def check_1007(solution, rng):
    tests = []
    for _ in range(80):
        n = rng.choice((2, 4, 6, 8, 10))
        points = [(rng.randint(-100, 100), rng.randint(-100, 100)) for _ in range(n)]
        tx, ty = map(sum, zip(*points))
        expected = min(math.hypot(2 * sum(points[i][0] for i in chosen) - tx,
                                  2 * sum(points[i][1] for i in chosen) - ty)
                       for chosen in itertools.combinations(range(n), n // 2))
        tests.append((points, expected))
    tests += [([(100000, 100000)] * 20, 0),
              ([(100000, 100000)] * 10 + [(-100000, -100000)] * 10, 0)]
    data = f"{len(tests)}\n" + "".join(
        f"{len(points)}\n" + "".join(f"{x} {y}\n" for x, y in points)
        for points, _ in tests
    )
    actual = solution.run(data).split()
    if len(actual) != len(tests):
        raise AssertionError("1007: wrong number of answers")
    for value, (_, expected) in zip(actual, tests):
        if not math.isclose(float(value), expected, rel_tol=1e-9, abs_tol=1e-8):
            raise AssertionError(f"1007: {value} != {expected}")
    solution.cases += len(tests)


def check_1016(solution, rng):
    ranges = [(1, 1), (1, 10), (4, 4), (8, 8), (9, 9), (10, 10),
              (15, 17), (24, 26), (35, 37)]
    for _ in range(250):
        start = rng.randint(1, 10000)
        ranges.append((start, start + rng.randint(0, 200)))
    for start, end in ranges:
        expected = sum(all(value % (d * d) for d in range(2, math.isqrt(value) + 1))
                       for value in range(start, end + 1))
        solution.expect(f"{start} {end}\n", [expected])

    # Independent count using a linear Mobius sieve, not interval marking.
    limit = math.isqrt(1000001000000)
    mu, composite, primes = [0] * (limit + 1), bytearray(limit + 1), []
    mu[1] = 1
    for value in range(2, limit + 1):
        if not composite[value]:
            primes.append(value)
            mu[value] = -1
        for prime in primes:
            multiple = value * prime
            if multiple > limit:
                break
            composite[multiple] = 1
            if value % prime == 0:
                break
            mu[multiple] = -mu[value]

    def count_up_to(bound):
        return sum(mu[d] * (bound // (d * d)) for d in range(1, math.isqrt(bound) + 1))

    ranges = [(1, 1000001), (999999999999, 1000000000000),
              (1000000000000, 1000000000000), (1000000000000, 1000001000000),
              (999998000000, 999998000002)]
    for _ in range(5):
        start = rng.randint(10**11, 10**12)
        ranges.append((start, start + rng.randint(0, 1000000)))
    for start, end in ranges:
        solution.expect(f"{start} {end}\n", [count_up_to(end) - count_up_to(start - 1)])


def is_prime(value):
    return value >= 2 and all(value % d for d in range(2, math.isqrt(value) + 1))


def check_1017(solution, rng):
    for _ in range(200):
        n = rng.choice((2, 4, 6, 8, 10))
        values = rng.sample(range(1, 70), n)

        @functools.lru_cache(None)
        def can_pair(rest):
            if not rest:
                return True
            return any(is_prime(rest[0] + rest[i]) and can_pair(rest[1:i] + rest[i + 1:])
                       for i in range(1, len(rest)))

        answer = sorted(values[j] for j in range(1, n)
                        if is_prime(values[0] + values[j])
                        and can_pair(tuple(values[1:j] + values[j + 1:]))) or [-1]
        solution.expect(f"{n}\n" + " ".join(map(str, values)) + "\n", answer)


def check_1018(solution, rng):
    boards = [["W" * 8] * 8, ["BW" * 4, "WB" * 4] * 4]
    for _ in range(100):
        n, m = rng.randint(8, 16), rng.randint(8, 16)
        boards.append(["".join(rng.choice("BW") for _ in range(m)) for _ in range(n)])
    for board in boards:
        n, m = len(board), len(board[0])
        expected = min(
            sum(board[row + x][column + y] != colors[(x + y) % 2]
                for x in range(8) for y in range(8))
            for row in range(n - 7) for column in range(m - 7) for colors in ("BW", "WB")
        )
        solution.expect(f"{n} {m}\n" + "\n".join(board) + "\n", [expected])


def check_1019(solution, rng):
    for n in list(range(1, 101)) + [999, 1000, 1001, 9999, 10000, 12345]:
        counts = [0] * 10
        for page in range(1, n + 1):
            for digit in str(page):
                counts[int(digit)] += 1
        solution.expect(f"{n}\n", counts)

    # Digit DP checks large limits without copying the solution's place-value formula.
    def digit_counts(bound):
        digits = tuple(map(int, str(bound)))

        @functools.lru_cache(None)
        def visit(position, tight, started):
            if position == len(digits):
                return int(started), (0,) * 10
            total, counts = 0, [0] * 10
            for digit in range((digits[position] if tight else 9) + 1):
                active = started or digit != 0
                ways, child = visit(position + 1, tight and digit == digits[position], active)
                total += ways
                for i in range(10):
                    counts[i] += child[i]
                if active:
                    counts[digit] += ways
            return total, tuple(counts)

        return visit(0, True, False)[1]

    for n in [10**k + offset for k in range(1, 10) for offset in (-1, 0, 1)
              if 1 <= 10**k + offset <= 10**9] + [rng.randint(1, 10**9) for _ in range(30)]:
        solution.expect(f"{n}\n", digit_counts(n))


def check_1021(solution, rng):
    for _ in range(100):
        n = rng.randint(1, 50)
        targets = rng.sample(range(1, n + 1), rng.randint(1, n))
        values, expected = list(range(1, n + 1)), 0
        for target in targets:
            index = values.index(target)
            expected += min(index, len(values) - index)
            values = values[index + 1:] + values[:index]
        solution.expect(f"{n} {len(targets)}\n" + " ".join(map(str, targets)) + "\n", [expected])


def check_1022(solution, rng):
    # Generate a small spiral by walking, independently of the coordinate formula.
    grid = {(0, 0): 1}
    row = column = 0
    value, length, direction = 1, 1, 0
    directions = ((0, 1), (-1, 0), (0, -1), (1, 0))
    while value < 10201:
        for _ in range(2):
            dr, dc = directions[direction % 4]
            for _ in range(length):
                row, column, value = row + dr, column + dc, value + 1
                grid[row, column] = value
            direction += 1
        length += 1
    for _ in range(100):
        r1, c1 = rng.randint(-20, 20), rng.randint(-20, 20)
        r2, c2 = r1 + rng.randint(0, 10), c1 + rng.randint(0, 5)
        rows = [[grid[r, c] for c in range(c1, c2 + 1)] for r in range(r1, r2 + 1)]
        width = len(str(max(map(max, rows))))
        expected = "\n".join(" ".join(f"{v:>{width}}" for v in row) for row in rows) + "\n"
        actual = solution.run(f"{r1} {c1} {r2} {c2}\n")
        if actual != expected:
            raise AssertionError(f"1022: value/alignment mismatch\n{actual!r}\n{expected!r}")
        solution.cases += 1
    for r, c, value in [(0, 0, 1), (5000, 5000, 100020001),
                        (5000, -5000, 100010001), (-5000, -5000, 100000001),
                        (-5000, 5000, 99990001)]:
        solution.expect(f"{r} {c} {r} {c}\n", [value])


def check_1024(solution, rng):
    # Enumerate nonnegative starts for small sums rather than solving the formula.
    tests = [(rng.randint(1, 500), rng.randint(2, 100)) for _ in range(500)]
    for target, minimum in tests:
        expected = [-1]
        for length in range(minimum, 101):
            for start in range(target // length + 1):
                candidate = list(range(start, start + length))
                if sum(candidate) == target:
                    expected = candidate
                    break
            if expected != [-1]:
                break
        solution.expect(f"{target} {minimum}\n", expected)
    for target, minimum, answer in [(1, 2, [0, 1]), (4950, 100, list(range(100))),
                                    (1000000000, 2, range(199999998, 200000003)),
                                    (1000000000, 100, [-1])]:
        solution.expect(f"{target} {minimum}\n", answer)


def check_1026(solution, rng):
    for _ in range(80):
        n = rng.randint(1, 7)
        values = [rng.randint(0, 100) for _ in range(n)]
        weights = [rng.randint(0, 100) for _ in range(n)]
        expected = min(sum(a * b for a, b in zip(order, weights))
                       for order in itertools.permutations(values))
        solution.expect(f"{n}\n" + " ".join(map(str, values)) + "\n"
                        + " ".join(map(str, weights)) + "\n", [expected])
    solution.expect("50\n" + "100 " * 50 + "\n" + "100 " * 50 + "\n", [500000])


def check_1028(solution, rng):
    boards = [["1"], ["0"], ["1" * 8], ["1"] * 8,
              ["010", "101", "010"], ["010", "111", "010"],
              ["010", "101", "000"]]
    for _ in range(150):
        rows, columns = rng.randint(1, 9), rng.randint(1, 9)
        boards.append(["".join(rng.choice("01") for _ in range(columns)) for _ in range(rows)])
    for board in boards:
        rows, columns = len(board), len(board[0])
        expected = 0
        for top in range(rows):
            for center in range(columns):
                for size in range(1, min(rows, columns) + 1):
                    cells = set()
                    for offset in range(size):
                        cells.update(((top + offset, center - offset),
                                      (top + offset, center + offset),
                                      (top + size - 1 + offset, center - size + 1 + offset),
                                      (top + size - 1 + offset, center + size - 1 - offset)))
                    if all(0 <= r < rows and 0 <= c < columns and board[r][c] == "1"
                           for r, c in cells):
                        expected = max(expected, size)
        solution.expect(f"{rows} {columns}\n" + "\n".join(board) + "\n", [expected])
    for digit, expected in (("0", 0), ("1", 375)):
        solution.expect("750 750\n" + ((digit * 750 + "\n") * 750), [expected])


def check_1029(solution, rng):
    for _ in range(100):
        n = rng.randint(2, 8)
        prices = [[rng.randrange(10) for _ in range(n)] for _ in range(n)]

        def longest_chain(owner, last_price, remaining):
            return 1 + max([longest_chain(buyer, prices[owner][buyer], remaining - {buyer})
                            for buyer in remaining if prices[owner][buyer] >= last_price] + [0])

        expected = longest_chain(0, 0, set(range(1, n)))
        data = f"{n}\n" + "\n".join("".join(map(str, row)) for row in prices) + "\n"
        solution.expect(data, [expected])
    for digit in ("0", "9"):
        solution.expect("15\n" + (digit * 15 + "\n") * 15, [15])


def check_1037(solution, rng):
    # Build complete divisor sets from a known number, rather than multiplying input extremes.
    numbers = [4, 6, 9, 12, 36, 1000000, 46337 * 46337]
    while len(numbers) < 107:
        number = rng.randint(4, 100000)
        if not is_prime(number):
            numbers.append(number)
    for number in numbers:
        divisors = set()
        for divisor in range(2, math.isqrt(number) + 1):
            if number % divisor == 0:
                divisors.update((divisor, number // divisor))
        if not divisors or len(divisors) > 50 or max(divisors) > 1000000:
            continue
        divisors = list(divisors)
        rng.shuffle(divisors)
        solution.expect(f"{len(divisors)}\n" + " ".join(map(str, divisors)) + "\n", [number])


def check_1043(solution, rng):
    cases = [(3, set(), [{1, 2}, {2, 3}]),
             (4, {1}, [{3, 4}, {2, 3}, {1, 2}]),
             (4, {1}, [{1, 2}, {3, 4}])]
    for _ in range(150):
        n = rng.randint(1, 12)
        known = set(rng.sample(range(1, n + 1), rng.randint(0, n)))
        parties = [set(rng.sample(range(1, n + 1), rng.randint(1, n)))
                   for _ in range(rng.randint(1, 12))]
        cases.append((n, known, parties))
    cases.append((50, {1}, [set(range(1, 51)) for _ in range(50)]))
    for n, known, parties in cases:
        informed = known.copy()
        while True:
            expanded = informed.copy()
            for party in parties:
                if party & informed:
                    expanded |= party
            if expanded == informed:
                break
            informed = expanded
        expected = sum(not (party & informed) for party in parties)
        data = f"{n} {len(parties)}\n{len(known)} " + " ".join(map(str, sorted(known))) + "\n"
        data += "".join(f"{len(party)} " + " ".join(map(str, sorted(party))) + "\n" for party in parties)
        solution.expect(data, [expected])


def check_1057(solution, rng):
    def meeting_round(n, first, second):
        players, round_number = list(range(1, n + 1)), 0
        while len(players) > 1:
            round_number += 1
            winners = []
            for index in range(0, len(players), 2):
                pair = players[index:index + 2]
                if first in pair and second in pair:
                    return round_number
                winners.append(first if first in pair else second if second in pair else pair[0])
            players = winners
        raise AssertionError("Distinct players must meet")

    cases = [(n, first, second) for n in range(2, 11)
             for first in range(1, n + 1) for second in range(first + 1, n + 1)]
    for _ in range(100):
        n = rng.randint(2, 100)
        first, second = rng.sample(range(1, n + 1), 2)
        cases.append((n, first, second))
    cases += [(100000, 1, 100000), (100000, 99999, 100000)]
    for n, first, second in cases:
        solution.expect(f"{n} {first} {second}\n", [meeting_round(n, first, second)])


def check_1058(solution, rng):
    boards = [["N"], ["NNN"] * 3, ["NYN", "YNY", "NYN"],
              ["NYY", "YNY", "YYN"], ["NYNN", "YNYN", "NYNY", "NNYN"]]
    for _ in range(150):
        n = rng.randint(2, 15)
        board = [["N"] * n for _ in range(n)]
        for i in range(n):
            for j in range(i + 1, n):
                board[i][j] = board[j][i] = rng.choice("YN")
        boards.append(["".join(row) for row in board])
    boards += [["N" * 50] * 50,
               ["".join("N" if i == j else "Y" for j in range(50)) for i in range(50)]]
    for board in boards:
        n, expected = len(board), 0
        for person in range(n):
            visited, frontier = {person}, {person}
            for _ in range(2):
                frontier = {j for i in frontier for j in range(n) if board[i][j] == "Y"} - visited
                visited |= frontier
            expected = max(expected, len(visited) - 1)
        solution.expect(f"{n}\n" + "\n".join(board) + "\n", [expected])


def check_1069(solution, rng):
    cases = [(3, 4, 1, 2), (3, 4, 5, 5), (3, 4, 5, 2),
             (3, 4, 10, 1), (3, 4, 10, 4), (6, 8, 5, 1), (1000, 1000, 1, 1)]
    cases += [(rng.randint(1, 1000), rng.randint(1, 1000),
               rng.randint(1, 10000), rng.randint(1, 10000)) for _ in range(150)]
    for x, y, length, duration in cases:
        distance = math.hypot(x, y)
        expected = distance
        # Enumerate jump counts; 2+ jumps can attain any resultant distance from 0 to k*D.
        for jumps in range(1, math.ceil(distance / length) + 3):
            remaining = abs(distance - length) if jumps == 1 else max(0.0, distance - jumps * length)
            expected = min(expected, jumps * duration + remaining)
        data = f"{x} {y} {length} {duration}\n"
        actual = solution.run(data).split()
        if len(actual) != 1 or not math.isclose(float(actual[0]), expected, rel_tol=1e-9, abs_tol=1e-9):
            raise AssertionError(f"1069: {data!r}: expected one value {expected}, got {actual}")
        solution.cases += 1


def check_1072(solution, rng):
    cases = [(played, won) for played in range(1, 41) for won in range(played + 1)]
    for played, won in cases:
        percentage = 100 * won // played
        expected = next((wins for wins in range(1, played + 1)
                         if 100 * (won + wins) // (played + wins) > percentage), -1)
        solution.expect(f"{played} {won}\n", [expected])
    cases = [(1000000000, 980000000), (1000000000, 990000000), (1000000000, 0)]
    for _ in range(150):
        played = rng.randint(1, 1000000000)
        cases.append((played, rng.randint(0, played)))
    for played, won in cases:
        percentage = 100 * won // played
        if percentage >= 99:
            expected = -1
        else:
            low, high = 1, 10000000000
            while low < high:
                middle = (low + high) // 2
                if 100 * (won + middle) // (played + middle) > percentage:
                    high = middle
                else:
                    low = middle + 1
            expected = low
        solution.expect(f"{played} {won}\n", [expected])


def check_1074(solution, rng):
    for exponent in range(1, 4):
        positions = []

        def visit(row, column, size):
            if size == 1:
                positions.append((row, column))
                return
            half = size // 2
            for dr, dc in ((0, 0), (0, half), (half, 0), (half, half)):
                visit(row + dr, column + dc, half)

        visit(0, 0, 1 << exponent)
        for expected, (row, column) in enumerate(positions):
            solution.expect(f"{exponent} {row} {column}\n", [expected])
    cases = [(15, 32767, 32767), (15, 0, 0)]
    for _ in range(150):
        exponent = rng.randint(1, 15)
        cases.append((exponent, rng.randrange(1 << exponent), rng.randrange(1 << exponent)))
    for exponent, row, column in cases:
        expected = sum(((row >> bit) & 1) << (2 * bit + 1) for bit in range(exponent))
        expected += sum(((column >> bit) & 1) << (2 * bit) for bit in range(exponent))
        solution.expect(f"{exponent} {row} {column}\n", [expected])


CHECKS = {number: globals()[f"check_{number}"] for number in PROBLEMS}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("problems", nargs="*", type=int, help="Reviewed BOJ numbers; default: all reviewed problems")
    parser.add_argument("--compiler", default=os.environ.get("CXX", "g++"))
    parser.add_argument("--sanitize", action="store_true", help="Enable undefined-behavior sanitizer")
    args = parser.parse_args()
    selected = args.problems or PROBLEMS
    if any(problem not in CHECKS for problem in selected):
        parser.error(f"Supported problems: {', '.join(map(str, PROBLEMS))}")
    flags = ["-std=c++17", "-O2", "-Wall", "-Wextra", "-Werror", "-D_GLIBCXX_ASSERTIONS"]
    if args.sanitize:
        flags += ["-fsanitize=undefined", "-fno-sanitize-recover=all"]
    total = 0
    with tempfile.TemporaryDirectory(prefix="ps-verify-") as temporary:
        for problem in selected:
            executable = Path(temporary) / f"{problem}.exe"
            source = ROOT / "BOJ" / str(problem) / f"{problem}.cpp"
            subprocess.run(shlex.split(args.compiler) + flags + [str(source), "-o", str(executable)],
                           check=True, timeout=60)
            solution = Solution(problem, executable)
            CHECKS[problem](solution, random.Random(problem))
            total += solution.cases
            print(f"BOJ {problem}: PASS ({solution.cases} cases)", flush=True)
    print(f"PASS: {len(selected)} solutions, {total} cases")


if __name__ == "__main__":
    main()
