#include<bits/stdc++.h>
#define maxn 1000010
using namespace std;
class edge {
public:
	int from, to, dist;
	edge(int a = 0, int b = 0, int c = 0) :from(a), to(b), dist(c) {}
	bool operator < (const edge b) const { return dist < b.dist; }
};
int n, m, p[maxn], tot = 0, ans = 0;
vector<edge> edges;
int find(int x) {
	return p[x] == x ? x : find(p[x]);
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			edges.push_back(edge(i, j, x));
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++) {
		edge& e = edges[i];
		int x = find(e.from), y = find(e.to);
		if (x != y) {
			p[x] = y;
			ans++;
			tot += e.dist;
			if (ans == n - 1) break;
		}
	}
	cout << tot << endl;
	return 0;
}