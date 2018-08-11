#include<bits/stdc++.h>
using namespace std;
struct trash{
	int t, f, h;
	bool operator < (const trash &b) const { return t < b.t; }
} item[110];
int dp[110] = { 10 };
int d, g, ans = -1;
int main() {
	scanf("%d%d", &d, &g);
	for (int i = 1; i <= g; i++) scanf("%d%d%d", &item[i].t, &item[i].f, &item[i].h);
	sort(item + 1, item + g + 1);
	for (int i = 1; i <= g; i++) {
		trash &x = item[i];
		for (int j = d; j >= 0; j--) {
			if (dp[j] >= x.t) {
				if (j + x.h >= d) {
					printf("%d\n", x.t);
					return 0;
				}
				if (j + x.h < d) dp[j + x.h] = max(dp[j + x.h], dp[j]);
				dp[j] += x.f;
			}
		}
	}
	printf("%d\n", dp[0]);
	return 0;
}