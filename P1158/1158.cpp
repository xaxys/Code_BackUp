#include<iostream>
#include<algorithm>
using namespace std;
int x_1, y_1, x_2, y_2, n, dis1[100010], dis2[100010],order[100010], minfee, maxdis2=0;
int cmp(int a, int b) {
	return dis1[a] > dis1[b];
}
int main() {
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dis1[i] = (x - x_1)*(x - x_1) + (y - y_1)*(y - y_1);
		dis2[i] = (x - x_2)*(x - x_2) + (y - y_2)*(y - y_2);
		order[i] = i;
	}
	sort(order, order + n, cmp);
	minfee = dis1[order[0]];
	for (int i = 1; i < n; i++) {
		maxdis2 = max(maxdis2, dis2[order[i-1]]);
		minfee = min(minfee, dis1[order[i]] + maxdis2);
	}
	minfee = min(minfee,max(maxdis2,dis2[order[n-1]]));
	cout << minfee << endl;
	return 0;
}