#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b) ? (a):(b))
using namespace std;
int n, m, cat[500000], fri[500000], s, p, maxp[500000], order[500000], ans = 0, now;
vector<int> g[500000],g2[500000],dfsorder;
void init() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[y].push_back(x);
		g2[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cat[i]);
	}
	scanf("%d%d", &s, &p);
	for (int i = 1; i <= p; i++) {
		scanf("%d", &fri[i]);
	}
	memset(order, 0, sizeof(order));
	memset(maxp, 0, sizeof(maxp));
}
int dfs(int x) {
	if (x == s) return cat[s];
	int cats = cat[x];
	dfsorder.push_back(x);
	now = dfsorder.size() - 1;
	for (int i = 0; i <= g[x].size() - 1; i++){
		int k = g[x][i];
		if (!order[k]) {
			if (!maxp[k]) {
				int t = dfs(k);
				if (t == -1){
					t = 0;
					if (order[x] != now) {
						for (int j = 0; j <= g[x].size() - 1; j++) {
							g[dfsorder[now]].push_back(g[x][j]);
						}
						for (int j = 0; j <= g2[x].size() - 1; j++) {
							int a = g2[x][j];
							vector<int>::iterator result = find(g[a].begin(), g[a].end(), x);
							g[a].erase(result);
							g[a].push_back(dfsorder[now]);
						}
						dfsorder.pop_back();
						cat[dfsorder[now]] += cat[x];
						return -1;
					}
				}
				maxp[k] = t;
			}
			cats += maxp[k];
		}
		else {
			now = order[k];
			dfsorder.pop_back();
			cat[k] += cat[x];
			return -1;
		}
	}
	return cats;
}
int main() {
	init();
	for (int i = 1; i <= p; i++) {
		ans = max(ans, dfs(fri[i]));
	}
	printf("%d", ans);
	return 0;
}