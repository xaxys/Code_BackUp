#include<bits/stdc++.h>
#define N 30001
using namespace std;
int t, f[N], len[N], sz[N];
int find(int x) { 
	if (f[x] == x) return x;
	int a = find(f[x]);
	len[x] += len[f[x]];
	return f[x] = a;
}
inline void connect(int x, int y) {
	x = find(x); y = find(y);
	f[x] = y;
	len[x] += sz[y];
	sz[y] += sz[x];
}
inline int check(int x, int y) { 
	return find(x) == find(y) ? abs(len[x] - len[y]) - 1 : -1; 
}
int main() {
	for (int i = 1; i < N; i++) {
		f[i] = i; sz[i] = 1; len[i] = 0;
	}
	scanf("%d%*[^\n]%*c", &t);
	char ch; int x, y;
	while (t--) {
		scanf("%c%d%d%*[^\n]%*c", &ch, &x, &y);
		if (ch == 'M') connect(x, y);
		else printf("%d\n", check(x, y));
	}
	return 0;
}
