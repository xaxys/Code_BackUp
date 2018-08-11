#include<bits/stdc++.h>
using namespace std;
class edge {
public:
	int from, to, dist;
	edge(int a = 0, int b = 0, int c = 0) :from(a), to(b), dist(c) {}
};

int n, m, s, d[20000], vis[20000];
vector<edge> edges;
vector<int> g[20000];

void addedge() {
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		edges.push_back(edge(x, y, z));
		g[x].push_back(edges.size() - 1);
	}
}

void spfa_SLF() {
	list<int> q;
	q.push_back(s);
	d[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		vis[u] = 0;
		for (int i = 0; i < g[u].size(); i++) {
			edge& e = edges[g[u][i]];
			if (d[e.to] > d[u] + e.dist) {
				d[e.to] = d[u] + e.dist;
				if (!vis[e.to]) {
					vis[e.to] = 1;
					if (!q.empty() && d[q.front()] > d[e.to]) q.push_front(e.to);
					else q.push_back(e.to);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) d[i] = INT_MAX;
	addedge();
	spfa_SLF();
	for (int i = 1; i <= n; i++) cout << d[i] << " ";
	return 0;
}