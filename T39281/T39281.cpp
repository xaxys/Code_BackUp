#include<bits/stdc++.h>
#define INF 0x7f7f7f7f
#define N 60
#define E 3000
using namespace std;
int n, m, k, T, L, d[N][N], ans;
string s;
inline int get1(int x) { return x - 'a' + 1; }
inline int get2(int x) { return x - 'a' + 27; }
int check(int x, int len) {
	if (len <= 1) return 0;
	int k = min(d[get1(s[x])][get2(s[x + len - 1])], d[get1(s[x + len - 1])][get2(s[x])]);
	return check(x + 1, len - 2) + k;
}
void floyd() {
	for (int k = 1; k <= 52; k++)
		for (int i = 1; i <= 52; i++)
			for (int j = 1; j <= 52; j++)
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> k >> T;
	cin >> s;
	for (int i = 1; i <= 52; i++)
		for (int j = 1; j <= 52; j++)
			d[i][j] = 5;
	for (int i = 1; i <= m; i++) {
		char a, b; int x;
		cin >> a >> b >> x;
		d[get1(a)][get1(b)] = x;
		d[get2(b)][get2(a)] = x;
	}
	for (int i = 'a'; i <= 'z'; i++) d[get1(i)][get2(i)] = 0;
	floyd();
	for (int i = 1; i <= n - k + 1; i++) ans += check(i - 1, k);
	printf("%d\n", ans);
	return 0;
}