#include<bits/stdc++.h>
#define N 2500
using namespace std;
int n, k, t[N << 1], ord[N << 1];
int f[N][2];
int cmp(int a, int b) { return t[a] < t[b]; }
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &t[i], &t[i + n]);
	for (int i = 1; i <= n + n; i++) ord[i] = i;
	sort(ord + 1, ord + n + n + 1, cmp);
	memset(f, 0x7f, sizeof(f));
	f[k][0] = 0;
	for (int i = 1; i <= n + n; i++) {
		if (ord[i] <= n) {
			for (int j = 0; j < k; j++) {
				f[j][0] = min(f[j + 1][0], f[j + 1][1] + t[ord[i]] - t[ord[i - 1]]);
				f[j][1] = min(f[j][0], f[j][1] + t[ord[i]] - t[ord[i - 1]]);
				f[j][1] = min(f[j][1], f[j][0]);
			}
		}
		else {
			for (int j = k; j >= 1; j--) {
				int tmp = min(f[j - 1][1], f[j][1]);
				f[j][0] = min(f[j - 1][0], tmp + t[ord[i]] - t[ord[i - 1]]);
				f[j][1] = f[j][0];
			}
		}
	}
	printf("%d\n", f[k][0]);
	return 0;
}