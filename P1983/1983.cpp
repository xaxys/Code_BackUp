#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, m, gin[1001], gout[1001], ans = 1;
bool g[1001][1001];
queue<int> q;
void check() {
	for (int i = 1; i <= n; i++) if (!gin[i] && gout[i]) q.push(i);
}
int main() {
	memset(g, 0, sizeof(g));
	memset(gin, 0, sizeof(gin));
	memset(gout, 0, sizeof(gout));
	cin >> n >> m;
	while (m--) {
		int x, t[1001], k = 2;
		cin >> x;
		for (int i = 1; i <= x; i++) cin >> t[i];
		for (int j = t[1] + 1; j <= t[x]; j++) {
			if (j != t[k]) {
				for (int a = 1; a <= x; a++)
					if (!g[j][t[a]]) {
						gin[t[a]]++;
						gout[j]++;
						g[j][t[a]] = 1;
					}
			}
			else k++;
		}
	}
	check();
	while (!q.empty()) {
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 1; i <= 1000; i++) {
				if (g[x][i]) {
					gin[i]--;
					gout[x]--;
				}
			}
		}
		check();
		ans++;
	}
	cout << ans << endl;
}