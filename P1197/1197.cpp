#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<set>
#define N 400010
#define M 200010
#define PF e[i].first
#define PS e[i].second
using namespace std;
int m, n, k, f[N], destoryed[N], tot;
int sta[N], ans[N];
vector<int> g[N];
pair<int, int> e[N];
int find(int x) {
	return f[x] == x ? x : find(f[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		e[i] = make_pair(x, y);
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		int x;
		scanf("%d", &x);
		sta[i] = x;
		destoryed[x] = 1;
	}
	tot = n - k;
	for (int i = 0; i < n; i++) f[i] = i;
	for (int i = 0; i < m; i++) {
		if (!destoryed[PF] && !destoryed[PS]) {
			int x = find(PF), y = find(PS);
			if (x != y) {
				f[x] = y;
				tot--;
			}
		}
	}
	ans[k + 1] = tot;
	for (int i = k; i > 0; i--) {
		int x = sta[i], siz = 0;
		destoryed[x] = 0;
		for (int i = 0; i < g[x].size(); i++) {
			if (!destoryed[g[x][i]]) {
				int a = find(g[x][i]), b = find(x);
				if (a != b) {
					f[b] = a;
					siz++;
				}
			}
		}
		ans[i] = tot = tot - siz + 1;
	}
	for(int i = 1; i <= k + 1; i++) printf("%d\n", ans[i]);
	return 0;
}