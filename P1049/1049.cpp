#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
bool dp[20010];
int n, v;
int main() {
	memset(dp, 0, sizeof(dp));
	scanf("%d", &v);
	scanf("%d", &n);
	dp[0] = 1;
	while (n--) {
		int x;
		scanf("%d", &x);
		for (int i = v; i > 0; i--) {
			if ((i - x) < 0) break;
			if (dp[i - x]) dp[i] = 1;
		}
	}
	int i = v;
	for (; i > 0; i--) {
		if (dp[i]) break;
	}
	printf("%d\n", v - i);
	return 0;
}