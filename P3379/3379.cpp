#include<cstdio>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
using namespace std;
vector<int> g[500010];
int n, m, st, s, fa[500010][25], depth[500010];

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar());
	return x*f;
}

void dfsinit(int x) {
	for (int i = 1; i <= s; i++) {
		if (!depth[fa[x][i - 1]]) break;
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (int i = 0; i < g[x].size(); i++){
		int p = g[x][i];
		if (p != fa[x][0]) {
			fa[p][0] = x;
			depth[p] = depth[x] + 1;
			dfsinit(p);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	/*for (int i = s; i >= 0; i--) {
		if (depth[a] < depth[b] && depth[a] <= depth[fa[b][i]]) b = fa[b][i];
	}*/
	int d = depth[b] - depth[a];
	for (int i = 0; i <= s; i++) if ((1 << i) & d) b = fa[b][i];
	if (a == b) return a;
	for (int i = s; i >= 0; i--) {
		if (fa[a][i] != fa[b][i]) {
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return fa[a][0];
}
int main() {
	n = read(); m = read(); st = read();
	s = floor(log(n + 0.0) / log(2.0));
	for (int i = 1; i < n; i++) {
		int x = read(), y = read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	fa[st][0] = 0;
	depth[st] = 1;
	dfsinit(st);
	int a, b;
	while (m--) {
		a = read(); b = read();
		printf("%d\n", lca(a, b));
	}
	return 0;
}