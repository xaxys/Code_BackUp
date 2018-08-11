#include<bits/stdc++.h>
#define N 3000
#define V 310
using namespace std;
int n, m, v, e;
int c[N], d[N];
float k[N];
int g[V][V], dist[V][V];
int tot;
int main() {
	scanf("%d%d%d%d", &n, &m, &v, &e);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
	for (int i = 1; i <= n; i++) scanf("%f", &k[i]);
	memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= e; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a][b] = g[b][a] = w;
	}
	for (int t = 1; t <= e; t++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (g[i][j] > g[i][t] + g[t][j])
					g[i][j] = g[i][t] + g[t][j];
	for (int i = 1)
}