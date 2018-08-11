#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, dmax[110][110], dmin[110][110], maxn = 0, minn = 0x7f7f7f7f, sum[110] = { 0 };
void search(int l, int r, int& maxn, int& minn) {
	int big = 0, small = 0x7f7f7f7f;
	for (int i = l; i < r; i++) {
		if (dmax[l][i] < 0) search(l, i, dmax[l][i], dmin[l][i]);
		if (dmax[i+1][r] < 0) search(i+1, r, dmax[i+1][r], dmin[i+1][r]);
		big = max(dmax[l][i], dmax[i + 1][r]);
		small = min(dmin[l][i], dmin[i + 1][r]);
		maxn = max(big, maxn);
		minn = min(small, minn);
	}
	maxn += sum[r] - sum[l - 1];
	minn += sum[r] - sum[l - 1];
}
int main() {
	ios::sync_with_stdio(0);
	memset(dmax, -0x7f, sizeof(dmax));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dmax[i][i];
		dmin[i][i] = dmax[i][i];
		sum[i] = sum[i - 1] + dmax[i][i];
	}
	search(1, n, maxn, minn);
	cout << maxn << endl;
	cout << minn << endl;
	return 0;
}