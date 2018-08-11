#include<bits/stdc++.h>
using namespace std;
int n, k, a[100010];
void check(int x) {
	list< pair<int, int> > que;
	for (int i = 1; i <= n; i++) {
		if (!que.empty() && que.front().second == i) que.pop_front();
		while (!que.empty() && (a[i] > que.back().first ? x : x^1)) que.pop_back();
		que.push_back(make_pair(a[i], i + k));
		if (i >= k) printf("%d ", que.front().first);
	}
	putchar(10);
}
int main() {
	//freopen("testdata.in", "r", stdin);
	//freopen("result.ans", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	check(0);
	check(1);
	return 0;
}