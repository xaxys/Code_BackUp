#include<bits/stdc++.h>
using namespace std;
int n, humor[110], dp[110][2], bigboss;//0不选自己，1选自己
string name[110];
map<string, int> m;
vector<int> g[110];
void dfs(int x) {
	for (int i = 0; i < g[x].size(); i++) {
		int& u = g[x][i];
		dfs(u);
		dp[x][0] += max(dp[u][1], dp[u][0]);
		dp[x][1] += dp[u][0];
	}
	dp[x][1] += humor[x];
}
int main() {
	cin >> n;
	string *boss = new string[110];
	for (int i = 1; i <= n; i++) {
		string n, b;
		int x;
		cin >> n >> x >> b;
		name[i] = n;
		boss[i] = b;
		m[n] = i;
		humor[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		g[m[boss[i]]].push_back(i);
		if (boss[i] == "NOBODY") bigboss = i;
	}
	delete[] boss;
	dfs(bigboss);
	cout << max(dp[bigboss][0], dp[bigboss][1]) << endl;
	return 0;
}