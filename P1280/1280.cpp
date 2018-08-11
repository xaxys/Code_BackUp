#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, k, d[10010];
vector<int> g[10010];
int main() {
	memset(d, -0x7f, sizeof(d));
	d[1] = 0;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int p, t;
		cin >> p >> t;
		g[p].push_back(p+t);
	}
	for (int i = 1; i <= n; i++) {
		if (g[i].empty()) d[i + 1] = max(d[i+1], d[i] + 1);
		else for (int j = 0; j < g[i].size(); j++) d[g[i][j]] = max(d[g[i][j]], d[i]);
	}
	cout << d[n + 1] << endl;
	return 0;
}