#include<bits/stdc++.h>
#define maxn 2010
using namespace std;
int d[maxn], d2[maxn], maxl[maxn];
void dfs(int x) {
	d[x] = d2[x] = 0;
	for (int i = 0; i < g[x].size(); i++) {
		dfs(g[x][i]);
		if (d[x] < d[g[x][i]]) {
			d2[x] = d[x];
			d[x] = d[g[x][i]];
		}
		else if (d[g[x][i]] > d2[x]) {
			d2[x] = d[g[x][i]];
		}
	}
	maxl[x] = max(maxl[x], d[x] + d2[x]);
}
int main() {
	dfs();
}