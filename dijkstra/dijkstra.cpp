/*
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
class edge {
public:
	int from, to, dist;
	edge(int a = 0, int b = 0, int c = 0) :from(a), to(b), dist(c) {}
};
class point {
public:
	int u, d;
	point(int a = 0, int b = 0) :u(a), d(b) {}
	bool operator < (const point& b) const {
		return d > b.d;
	}
};
int n, m, s, d[20000], done[20000] = { 0 };
vector<edge> g[20000];
priority_queue<point> que;
int main() {
	for (int i = 1; i <= 20000; i++) d[i] = 2147483647;
	cin >> n >> m >> s;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].push_back(edge(x, y, z));
	}
	d[s] = 0;
	que.push(point(s, 0));
	while (!que.empty()) {
		point x = que.top();
		que.pop();
		done[x.u] = 1;
		for (int i = 0; i < g[x.u].size(); i++) {
			edge& e = g[x.u][i];
			if (done[e.to]) continue;
			if (d[e.to] > d[x.u] + e.dist) {
				d[e.to] = d[x.u] + e.dist;
				que.push(point(e.to, d[e.to]));
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << d[i] << " ";
	return 0;
}
*/

#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define N 10010
#define M 500010
using namespace std;
int n, m, s, d[N];
int to[M], nxt[M], v[M], head[N], ecnt;
struct point {
	int u, d;
	point(int a = 0, int b = 0) :u(a), d(b) {}
	bool operator < (const point& b) const {
		return d > b.d;
	}
};
inline void addedge(int& x, int& y, int& z) {
	to[++ecnt] = y;
	v[ecnt] = z;
	nxt[ecnt] = head[x];
	head[x] = ecnt;
}
void dijkstra() {
	bool done[N];
	memset(done, 0, sizeof(done));
	d[s] = 0;
	priority_queue<point> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.top().u;
		q.pop();
		done[x] = 1;
		for (int i = head[x]; i; i = nxt[i]) {
			int& u = to[i];
			if (!done[u] && d[x] + v[i] < d[u]) {
				d[u] = d[x] + v[i];
				q.push(point(u, d[u]));
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= n; i++) d[i] = 2147483647;
	while (m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z);
	}
	dijkstra();
	for (int i = 1; i <= n; i++) printf("%d ", d[i]);
	return 0;
}