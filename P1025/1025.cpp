#include <iostream>
using namespace std;
int ans=0;
void dfs(int sum, int depth, int lastnum) {
	if (depth==1 && sum >= lastnum) {
		ans++;
		return;
	}
	for (int i = lastnum; i <= sum/depth; i++) {
		dfs(sum - i, depth - 1, i);
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	dfs(n, k, 1);
	cout << ans << endl;
	return 0;
}