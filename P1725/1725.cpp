#include<cstdio>
#include<algorithm>
#define N 200010
using namespace std;
int n, l, r, f[N], a[N];
pair<int, int> q[N];
int head, tail;
int main() {
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
	q[++tail] = make_pair(0, n + 1);
	for (int i = n; i >= 0; i--) {
		if (i + l <= n) {
			while (head <= tail && q[tail].first < f[i + l]) tail--;
			q[++tail] = make_pair(f[i + l], i + l);
		}
		f[i] = a[i] + q[head].first;
		if (q[head].second == i + r) head++;
	}
	printf("%d\n", f[0]);
	return 0;
}