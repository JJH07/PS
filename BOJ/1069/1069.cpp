#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int startX, startY, jumpLength, jumpTime;
    std::cin >> startX >> startY >> jumpLength >> jumpTime;
    const double distance = std::hypot(startX, startY);
    const long long fullJumps = static_cast<long long>(distance / jumpLength);

    double minimumTime = distance;
    minimumTime = std::min(minimumTime, jumpTime + std::abs(distance - jumpLength));
    minimumTime = std::min(
        minimumTime, fullJumps * jumpTime + distance - fullJumps * jumpLength);
    // At least two jumps can change direction and cover any distance up to their total length.
    const long long jumpsWithoutWalking = std::max(2LL, fullJumps + 1);
    minimumTime = std::min(minimumTime, static_cast<double>(jumpsWithoutWalking * jumpTime));

    std::cout << std::fixed << std::setprecision(12) << minimumTime << '\n';
    return 0;
}
