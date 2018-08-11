///Î´¹ý
#include<bits/stdc++.h>
using namespace std;
int n, fa[1010], ans;
int head[1010], nxt[1010], to[1010], ecnt;
bool vis[1010];
struct node {
	int x, dep;
	node(int a = 0, int b = 0) : x(a), dep(b) {}
	bool operator < (const node& b) const {
		return dep < b.dep;
	}
};
priority_queue<node> q;
inline void addedge(int x, int y) {
	to[++ecnt] = y;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}
void dfs1(int x) {
	q.push(node(x, fa[x] + 1));
	for (int i = head[x]; i; i = nxt[i]) {
		dfs1(to[i]);
	}
}
void dfs2(int x) {
	vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		dfs2(to[i]);
	}
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
		node u = q.top();
		q.pop();
		printf("%d ", u.x);
		for (; !q.empty() && vis[(u = q.top()).x]; q.pop());
		ans++;
		dfs2(fa[fa[u.x]]);
	}
	printf("%d\n", ans);
	return 0;
}