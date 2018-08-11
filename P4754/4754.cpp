#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000010
#define L 110
using namespace std;
int n, m, k, l, a[N], r[L], w[N], x[N], v[N];
int le, ri, ans, t;
int check(int p) {
	int b[N], times = w[p] - 1, tmp = 0, add[N];
	memcpy(b, a, sizeof(a));
	memset(add, 0, sizeof(add));
	for (int i = 1; i <= p; i++) b[x[i - 1]] -= v[i - 1];
	for (int i = 1; i <= n; i++) {
		if (add[i] > 0) tmp -= add[i];
		if (b[i] + tmp < 1) {
			add[i + k] = 1 - (b[i] + tmp);
			times -= add[i + k];
			tmp = 1 - b[i];
		}
	}
	return times;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &l);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= l; i++) scanf("%d", &r[i]);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &w[i], &x[i], &v[i]);
	w[m + 1] = 0x7f7f7f7f;
	le = 1; ri = m + 1;
	while (le <= ri) {
		int mid = le + ri >> 1, time = check(mid);
		if (time >= 0) {
			ri = mid - 1;
			ans = mid;
			t = time;
		}
		else le = mid + 1;
	}
	printf("%d\n", w[ans] - t - 1);
	return 0;
}