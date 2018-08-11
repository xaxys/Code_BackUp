#include <iostream>
#include <deque>
using namespace std;
class point {
public:
	int x, y;
};
int main() {
	const int xp[4] = { 0,1,0,-1 },yp[4] = { 1,0,-1,0 };
	int n, i, j, a[32][32];
	deque<point> d;
	point temp;
	cin >> n;
	for (i = 0; i <= n+1; i++) {
		for (j = 0; j <= n+1; j++) {
			a[i][j] = 2;
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) a[i][j] = 2;
		}
	}
	temp.x = 0; temp.y = 0;
	d.push_back(temp);
	while (!d.empty()) {
		temp = d.front();
		d.pop_front();
		for (i = 0; i < 4; i++) {
			int xx = temp.x + xp[i], yy = temp.y + yp[i];
			if (xx <= n + 1 && xx >= 0 && yy <= n+1&&yy >= 0&&a[xx][yy]==2) {
					a[xx][yy] = 0;
					point t = { xx,yy };
					d.push_back(t);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j < n; j++) cout << a[i][j]<<" ";
		cout << a[i][n] << endl;
	}
}