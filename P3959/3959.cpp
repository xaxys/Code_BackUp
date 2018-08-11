//45分错误示范Prim
/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define open(s) ios::sync_with_stdio(false); freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin);fclose(stdout);
using namespace std;
class edge {
public:
	int from, to, dist;
	edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), dist(c) {}
	bool operator < (const edge& b) const {
		return dist>b.dist;
	}
};
int n, m, ans = 2147483647;
vector<edge> edges, edges_bak;
vector<int> g[20];
int cmp(edge a, edge b) {
	return a.dist<b.dist;
}
int search_(int x) {
	int depth[20], ans = 0, side = 0;
	bool done[20];
	memset(done, 0, sizeof(done));
	priority_queue<edge> q;
	depth[x] = 1;
	done[x] = 1;
	for (int i = 0; i<g[x].size(); i++) {
		edge& e = edges[g[x][i]];
		if (!done[e.to]) {
			q.push(e);
		}
	}
	while (!q.empty()) {
		edge x = q.top();
		q.pop();
		if (!done[x.to]) {
			done[x.to] = 1;
			side++;
			ans += x.dist;
			depth[x.to] = depth[x.from] + 1;
			for (int j = 0; j<g[x.to].size(); j++) {
				edge& e = edges[g[x.to][j]];
				if (!done[e.to]) {
					e.dist *= depth[x.to];
					q.push(e);
				}
			}
		}
		if (side == n - 1) break;
	}
	return ans;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i<m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edges_bak.push_back(edge(x, y, z));
		edges_bak.push_back(edge(y, x, z));
		g[x].push_back(edges_bak.size() - 2);
		g[y].push_back(edges_bak.size() - 1);
	}
	for (int i = 1; i <= n; i++) {
		edges.clear();
		for (int j = 0; j<edges_bak.size(); j++) {
			edges.push_back(edges_bak[j]);
		}
		int t = search_(i);
		//cout<<"i="<<i<<" t="<<t<<endl;
		if (t<ans) ans = t;
	}
	cout << ans << endl;
	return 0;
}
*/

//模拟退火Prim玄学A题，另外如果srand种子是20180325会WA一个点= =
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
struct edge {
	int from, to, dist;
	edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), dist(c) {}
	inline bool operator < (const edge& b) const {
		return dist > b.dist;
	}
};
int n, m, ans = 0x7f7f7f7f;
int mat[20][20];
int prim(int x) {
	int depth[20], ans = 0, done[20];
	memset(done, 0, sizeof(done));
	memset(depth, 0, sizeof(depth));
	priority_queue<edge> q;
	q.push(edge(0, x, 0));
	for(int side = 0; side < n; side++) {
		int top = 0;
		edge bak[200];
		edge e = q.top();
		q.pop();
		while (!q.empty() && (done[e.to] || !(rand() % n))) {
			if (!done[e.to]) bak[++top] = e;
			e = q.top();
			q.pop();
		}
		int& u = e.to;
		done[u] = 1;
		ans += e.dist;
		depth[u] = depth[e.from] + 1;
		for (int i = 1; i <= n; i++) {
			if (mat[u][i] == 0x7f7f7f7f) continue;
			if (!done[i]) q.push(edge(u, i, mat[u][i] * depth[u]));
		}
		while (top) q.push(bak[top--]);
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	memset(mat, 0x7f, sizeof(mat));
	srand(time(0));
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		mat[x][y] = mat[y][x] = min(mat[x][y], z);
	}
	for(int rad = 1; rad <= 1000; rad++){
		for (int i = 1; i <= n; i++) {
			ans = min(ans, prim(i));
		}
	}
	printf("%d\n", ans);
	return 0;
}
