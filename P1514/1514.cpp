#include<bits/stdc++.h>
#define N 510
using namespace std;
struct pos {
	int l, r;
	bool vis;
	pos() : l(INT_MAX), r(INT_MIN) {}
} cover[N][N];
const int nx[] = { 0, 1, 0, -1 }, ny[] = { -1, 0 , 1, 0 };
int n, m, height[N][N], nocover, ord[N];
bool kexin = 1;
bool cmp(int a, int b) {
	return cover[1][a].l < cover[1][b].l;
}
void init() {
	for (int i = 1; i <= m; i++) {
		cover[0][i].vis = 1;
		cover[n][i].l = cover[n][i].r = i;
	}
	for (int i = 0; i <= n; i++) {
		cover[i][0].vis = cover[i][m + 1].vis = 1;
	}
}
void dfs(int a, int b) {
#define p cover[a][b]
#define ne cover[x][y]
	if (p.vis) return;
	p.vis = 1;
	for (int i = 0; i < 4; i++) {
		int x = a + nx[i], y = b + ny[i];
		if (height[x][y] < height[a][b]) {
			dfs(x, y);
			if (p.l > ne.l) p.l = ne.l;
			if (p.r < ne.r) p.r = ne.r;
		}
	}
#undef ne
#undef p
}
int solve() {
#define p cover[1][ord[i]]
	int cnt = 0, last = 0, far = 0;
	for (int i = 1; i <= m; i++) {
		if (p.l == INT_MAX || p.r == INT_MIN) continue;
		if (last >= m) return cnt;
		if (p.l <= last + 1) far = max(far, p.r);
		else if (p.l > last + 1) {
			cnt++;
			last = far;
			if (p.l <= last + 1) far = max(far, p.r);
			else return -1;
		}
	}
	if (last < m && far >= m) return cnt + 1;
	if (far < m) return -1;
	return cnt;
#undef p
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &height[i][j]);
		}
	}
	init();
	for (int i = 1; i <= m; i++) dfs(1, i);
	for (int i = 1; i <= m; i++) {
		if (!cover[n][i].vis) {
			kexin = 0;
			nocover++;
		}
	}
	if (!kexin) printf("0\n%d\n", nocover);
	else {
		for (int i = 1; i <= m; i++) ord[i] = i;
		sort(ord + 1, ord + m + 1, cmp);
		printf("1\n%d\n", solve());
	}
	return 0;
}