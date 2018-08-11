#include<bits/stdc++.h>
using namespace std;
class edge {
public:
	int from, to, dist;
	edge(int a = 0, int b = 0, int c = 0) :from(a), to(b), dist(c) {}
};
class point {
public:
	int u, d;
	point(int a = 0, int b = 0) : u(a), d(b) {}
	bool operator < (const point b) const { return d > b.d; }
};
int n, m, s, d[20000], done[20000], num[20000];
vector<edge> edges;
vector<int> g[20000];

void addedge() {
	int(*map)[2010] = new int[2010][2010];
	memset(map, 0, sizeof(int) * 2010 * 2010);
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (map[x][y]) {
			edges[map[x][y]].dist = min(edges[map[x][y]].dist, z);
			continue;
		}
		edges.push_back(edge(x, y, z));
		g[x].push_back(edges.size() - 1);
		map[x][y] = edges.size() - 1;
	}
	delete[] map;
}

void dijkstra() {
	priority_queue<point> que;
	d[1] = 0;
	num[1] = 1;
	que.push(point(1, 0));
	while (!que.empty()) {
		point x = que.top();
		que.pop();
		done[x.u] = 1;
		for (int i = 0; i < g[x.u].size(); i++) {
			edge& e = edges[g[x.u][i]];
			if (d[e.to] == d[x.u] + e.dist) num[e.to]++;
			if (done[e.to]) continue;
			if (d[e.to] > d[x.u] + e.dist) {
				d[e.to] = d[x.u] + e.dist;
				que.push(point(e.to, d[e.to]));
				num[e.to] = 1;
			}
		}
	}
}

void spfa() {
	queue<int> q;
	q.push(1);
	d[1] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		done[u] = 0;
		for (int i = 0; i < g[u].size(); i++) {
			edge& e = edges[g[u][i]];
			if (d[e.to] == d[u] + e.dist) num[e.to]++;
			if (d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				num[e.to] = 1;
				if (!done[e.to]) {
					done[e.to] = 1;
					q.push(e.to);
				}
			}
		}
	}
}

int main() {
	memset(d, 0x7f, sizeof(d));
	cin >> n >> m;
	addedge();
	spfa();
	if (!num[n]) cout << "No answer" << endl;
	else cout << d[n] << " " << num[n] << endl;
	return 0;
}