#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
#define N_MAX 1000001
using namespace std;
int L, N, a[N_MAX];
int main() {
	while (scanf("%d %d", &L, &N) != EOF) {
		bool flag = false;
		L *= 1e7;
		for (int i = 0; i < N; i++) {
			scanf("%d", a + i);
		}
		sort(a, a + N);
		for (int i = 0; i < N; i++) {
			int val = L - a[i], idx = -1;
			int x = 0, y = N - 1;
			while (x <= y) {
				int mid = (x + y) >> 1;
				if (a[mid] > val) 
					y = mid - 1;
				else if (a[mid] < val)
					x = mid + 1;
				else {
					idx = mid;
					break;
				}
			}
			if (idx != -1 && idx != i) {
				printf("yes %d %d\n", a[i], a[idx]);
				flag = 1;
				break;
			}
		}
		if (!flag)	puts("danger");
	}
	return 0;
}