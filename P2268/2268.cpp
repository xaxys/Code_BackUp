#include<bits/stdc++.h>
using namespace std;
int T, n, num[15], ans;
void dfs(int left, int times) {
	if (left == 0) ans = min(ans, times);
	else {
		while()
	}
}
int main() {
	scanf("%d%d", &T, &n);
	while (T--) {
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d %*d", &x);
			num[x]++;
		}
		num[14] = num[1];
		num[1] = 0;
		ans = 0x7f7f7f7f;
		dfs(n, 0);
	}
}