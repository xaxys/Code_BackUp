#include<bits/stdc++.h>
using namespace std;
int n, fa[1010], ans;
int head[1010], nxt[1010], to[1010], ecnt;
bool vis[1010];
priority_queue< pair<int, int> > q;
inline void addedge(int x, int y) {
	to[++ecnt] = y;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}
void dfs1(int x) {
	q.push(make_pair(fa[x] + 1, x));
	for (int i = head[x]; i; i = nxt[i]) {
		dfs1(to[i]);
	}
}
void dfs2(int x, int time) {
	vis[x] = 1;
	if (time == 0) return;
	for (int i = head[x]; i; i = nxt[i]) {
		dfs2(to[i], time - 1);
	}
	dfs2(fa[x], time - 1);
}
int main() {
	scanf("%d", &n);
	fa[1] = 1;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &fa[i]);
		addedge(fa[i], i);
	}
	dfs1(1);
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		ans++;
		dfs2(fa[fa[u]], 2);
		for (; !q.empty() && vis[q.top().second]; q.pop());
	}
	printf("%d\n", ans);
	return 0;
}