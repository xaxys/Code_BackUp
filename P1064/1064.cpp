#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> mainitem, g[70];
int n, m, w[70], v[70], dp[32010];
int main() {
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int p, q;
		cin >> v[i] >> p >> q;
		w[i] = v[i] * p;
		if (!q) mainitem.push_back(i);
		else {
			g[q].push_back(i);
		}
	}
	for (int i = 0; i < mainitem.size(); i++) {
		int& item = mainitem[i];
		for (int k = n; k >= v[item]; k--) {
			dp[k] = max(dp[k], dp[k - v[item]] + w[item]);
			if (g[item].size() >= 1 && k - v[item] - v[g[item][0]] >= 0)
				dp[k] = max(dp[k], dp[k - v[item] - v[g[item][0]]] + w[item] + w[g[item][0]]);
			if (g[item].size() == 2) {
				if (k - v[item] - v[g[item][1]] >= 0)
					dp[k] = max(dp[k], dp[k - v[item] - v[g[item][1]]] + w[item] + w[g[item][1]]);
				if (k - v[item] - v[g[item][1]] - v[g[item][0]] >= 0)
					dp[k] = max(dp[k], dp[k - v[item] - v[g[item][1]] - v[g[item][0]]] + w[item] + w[g[item][1]] + w[g[item][0]]);
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}