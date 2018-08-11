#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
class edge {
public:
	int from, to, dist;
	edge(int a = 0, int b = 0, int c = 0) : from(a), to(b), dist(c) {}
};
int n, m, p[1000001], ans = 0, tot = 0;
vector<edge> edges;
int cmp(edge a,edge b) {
	return a.dist < b.dist;
}
int find(int x) {
	return p[x] == x ? x : find(p[x]);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edges.push_back(edge(x, y, z));
	}
	sort(edges.begin(), edges.begin() + m, cmp);
	for (int i = 0; i < m; i++) {
		edge& e = edges[i];
		int x = find(e.from), y = find(e.to);
		if (x != y) {
			p[x] = y;
			ans++;
			tot += e.dist;
		}
		if (ans == n - 1) break;
	}
	if (ans != n - 1) cout << "orz" << endl;
	else cout << tot << endl;
	return 0;
}