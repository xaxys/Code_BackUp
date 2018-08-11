#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class side {
public:
	int to, value;
	side(int a, int b) : to(a), value(b) {}
};
vector<side> g[300010];
int value[100010], m, n;
void addside(int x, int y) {
	g[x].push_back(side(y, 0));
	g[x].push_back(side(y + n, -value[y]));
	g[x+n].push_back(side(y + n, 0));
	g[x+n].push_back(side(y + 2 * n, value[y]));
	g[x+2*n].push_back(side(y + 2 * n, 0));
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> value[i];
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		addside(x, y);
		if (z == 2) addside(y, x);
	}
	g[n].push_back(side(3 * n + 1, 0));
	g[3 * n].push_back(side(3 * n + 1, 0));
	//spfa
	queue<int> que;
	bool inq[300010] = { 0 };
	int d[300010];
	for (int i = 2; i <= 3 * n + 1; i++) d[i] = -2147483647;
	que.push(1);
	d[1] = 0;
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		inq[x] = 0;
		for (int i = 0; i < g[x].size(); i++) {
			side& s = g[x][i];
			if (d[x] + s.value > d[s.to]) {
				d[s.to] = d[x] + s.value;
				if (!inq[s.to]) {
					que.push(s.to);
					inq[s.to] = 1;
				}
			}
		}
	}
	cout << d[3 * n + 1] << endl;
	return 0;
}