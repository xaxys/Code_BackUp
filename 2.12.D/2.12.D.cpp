#include<bits/stdc++.h>
#define maxn 510
using namespace std;
class edge {
public:
	int from, to, v, l;
	edge(int a = 0, int b = 0, int c = 0, int d = 0) :from(a), to(b), v(c), l(d) {}
};
class point {
public:
	int u;
	double d, v;
	point(int a = 0, double b = 0, double c = 0) :u(a), d(b), v(c) {}
	bool operator < (const point b) const { return d > b.d; }
};
int n, m, d, fa[maxn];
double dist[maxn];
bool done[maxn];
vector<edge> g[maxn];
priority_queue<point> que;

void dijkstra() {
	dist[0] = 0;
	que.push(point(0, 0, 70));
	while (!que.empty()) {
		point x = que.top();
		que.pop();
		done[x.u] = 1;
		for (int i = 0; i < g[x.u].size(); i++) {
			edge& e = g[x.u][i];
			if (done[e.to]) continue;
			double limit = e.v == 0 ? x.v : e.v;
			double time = e.l / limit;
			if (dist[e.to] > dist[x.u] + time) {
				fa[e.to] = x.u;
				dist[e.to] = dist[x.u] + time;
				que.push(point(e.to, dist[e.to], limit));
			}
		}
	}
}

void print(int d) {
	if (d == 0) {
		cout << d << " ";
		return;
	}
	print(fa[d]);
	cout << d << " ";
}
int main() {
	memset(fa, -0x3f, sizeof(fa));
	memset(dist, 0x7f, sizeof(dist));
	cin >> n >> m >> d;
	while (m--) {
		int a, b, v, l;
		cin >> a >> b >> v >> l;
		g[a].push_back(edge(a, b, v, l));
	}
	dijkstra();
	print(d);
	return 0;
}