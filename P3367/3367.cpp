#include<cstdio>
#define N 10010
using namespace std;
int n, m;
int f[N], rank[N];
inline void init() { for (int i = 1; i <= n; i++) f[i] = i; }
inline int find(int x) {
	while (f[x] != x) x = f[x];
	return x;
}
inline void connect(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (rank[x] < rank[y]) f[x] = y;
	else { f[y] = x; if (rank[x] == rank[y]) rank[x]++; }
}
int main() {
	scanf("%d%d", &n, &m);
	init();
	while (m--) {
		int x, y, z;
		scanf("%d%d%d", &z, &x, &y);
		if (z == 2) putchar(find(x) == find(y) ? 'Y' : 'N'), putchar(10);
		else connect(x, y);
	}
	return 0;
}