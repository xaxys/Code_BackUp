//Î´¹ý
#include<bits/stdc++.h>
using namespace std;
int n, a[60], b[60], maxn;
bool dfs(int len, int m) {
	if (len == 0) return 1;
	int f = 0;
	for (int i = min(len, m); i > 0 && !f; i--) {
		if (b[i] && !f) {
			b[i]--;
			if (dfs(len - i, i)) f = 1;
		}
	}
	return f;
}
int main() {
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {
		int x;
		scanf("%d", &x);
		if (x <= 50) a[x]++, maxn = max(maxn, x);
		else n--;
	}
	for (int i = maxn; i <= n * 50; i++) {
		int f = 1;
		memcpy(b, a, 60 * sizeof(int));
		for (int j = maxn; j > 0 && f; j--) {
			while (b[j] && f) {
				b[j]--;
				if (!dfs(i - j, j)) f = 0;
			}
		}
		if (f) {
			printf("%d\n", i);
			return 0;
		}
	}		
}