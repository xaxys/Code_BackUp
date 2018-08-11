#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
int n, m, s, w[N];
int rec[N], ptr;
int vis[N];
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
	w[m + 1] = n;
	for (int i = 1, pre = 0; i <= m + 1; i++) {
		if (w[i] - w[pre] >= s) {
			vis[i] = 1;
			rec[++ptr] = i;
			pre = i;
		}
	}
	for (int i = m, pre = m + 1; i >= 0; i--) {
		if (w[pre] - w[i] >= s && !vis[i]) {
			vis[i] = 1;
			rec[++ptr] = i;
			pre = i;
		}
	}
	if (ptr != m + 2) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 1; i <= ptr; i++) printf("%d ", rec[i]);
	}
	return 0;
}