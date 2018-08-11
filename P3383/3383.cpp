#include<cstdio>
#define N 10000010
#define int long long
using namespace std;
int x, n, m, pr[N >> 1], cnt;
bool f[N] = { 1, 1 };
#undef int
int main() {
#define int long long
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++) {
		if (!f[i]) pr[cnt++] = i;
		for (int j = 0; j < cnt && i * pr[j] <= n; j++) {
			f[i * pr[j]] = 1;
			if (i % pr[j] == 0) break;
		}
	}
	while (m--) {
		scanf("%d", &x);
		printf(f[x] ? "No\n" : "Yes\n");
	}
	return 0;
}