#include<bits/stdc++.h>
#define N 2002
using namespace std;
int n, k, l[N], r[N];
int pl[N], pr[N];
struct point {
	int x, be;
	point(int a = 0, int b = 0) : x(a), be(b) {}
	bool operator < (const point b) const { return x < b.x; }
} p[N << 1];
int s[N], S;
bool vis[N];
int dp[N][N][2];
void dfs(int x) {
	s[++S] = p[x].be;
	vis[s[S]] = 1;
	int last = pr[p[x].be] - 1;
	if (p[last].x == l[p[last].be] && !vis[p[last].be]) dfs(last);
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]);
		p[i] = point(l[i], i);
		p[i + n] = point(r[i], i);
	}
	sort(p + 1, p + n + n + 1);
	int kkk = 0;
	for (int i = 1; i <= n << 1; i++) {
		if (p[i].x == l[p[i].be]) pl[p[i].be] = i;
		else pr[p[i].be] = i;
		if (i != 1 && p[i].x == l[p[i].be] && p[i - 1].x == r[p[i - 1].be])
			kkk += p[i].x - p[i - 1].x;
	}
	for (int i = 1; i <= n << 1; i++)
		if (!vis[p[i].be]) dfs(i);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j][0] = max(dp[i - 1][j][1], dp[i - 1][j][0]);
			if (j) {
				if (pl[s[i]] + 1 == pr[s[i]]) {
					dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) +
						p[pr[s[i]]].x - p[pl[s[i]]].x;
					continue;
				}
				int last = p[pl[s[i]] + 1].be, rl = p[pr[s[i]] - 1].be, zuo = 0, you = 0;
				if (pl[rl] != pr[s[i]] - 1)
					you = p[pr[s[i]]].x - p[pr[s[i]] - 1].x;
				if (pr[last] != pl[s[i]] + 1)
					zuo = p[pl[s[i]] + 1].x - p[pl[s[i]]].x;
				else if (j >= 2)
					dp[i][j][1] = dp[i - 1][j - 1][1] + you + p[pl[s[i]] + 1].x - p[pl[s[i]]].x;
				dp[i][j][1] = max(dp[i][j][1], max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + zuo + you);
			}
		}
	}
	printf("%d\n", p[n + n].x - p[1].x - max(dp[n][k][0], dp[n][k][1]) - kkk);
	return 0;
}

