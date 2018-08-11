#include<iostream>
#include<cstring>
#include<vector>
#define open(s) ios::sync_with_stdio(false); freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin); fclose(stdout);
using namespace std;
int n, k, p, num[200010] = { 0 }, ans = 0;
vector<int> col[50];
int main() {
	open("hotel")
	cin >> n >> k >> p;
	for (int i = 1; i <= n; i++) {
		int color, price;
		cin >> color >> price;
		num[i] = num[i - 1] + (price <= p);
		col[color].push_back(i);
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < col[i].size() - 1; j++)
			for (int k = j + 1; k < col[i].size(); k++)
				if (num[col[i][k]] > num[col[i][j] - 1]) {
					ans += col[i].size() - k;
					break;
				}
	}
	cout << ans << endl;
	close;
	return 0;
}