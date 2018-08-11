#include<bits/stdc++.h>
using namespace std;
int n, ans, top;
pair<int, int> sta[500010];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		while (top && sta[top].first < x) ans += sta[top--].second;
		if (top && sta[top].first == x) ans += sta[top].second++;
		else sta[++top] = make_pair(x, 1);
		if (top > 1) ans += 1;
	}
	printf("%d\n", ans);
	return 0;
}