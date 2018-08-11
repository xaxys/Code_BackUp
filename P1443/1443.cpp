#include <iostream>
#include <queue>
#include <string.h>
#include <iomanip>
using namespace std;
class point {
public:
	int x, y;
};
queue<point> dui;
int sx, sy, nx, ny, a[500][500];
const int x[8] = { 1,2,2,1,-1,-2,-2,-1 }, y[8] = { 2,1,-1,-2,-2,-1,1,2 };
bool can(point k) {
	if (k.x <= nx&&k.y <= ny&&k.x >= 1 && k.y >= 1) return 1;
	return 0;
}
int main() {
	point tmp;
	int i, j;
	memset(a, -1, sizeof(a));
	cin >> nx >> ny >> sx >> sy;
	a[sx][sy] = 0;
	tmp.x = sx; tmp.y = sy;
	dui.push(tmp);
	while (!dui.empty()) {
		int time = a[dui.front().x][dui.front().y];
		for (i = 0; i < 8; i++) {
			tmp.x = dui.front().x + x[i];
			tmp.y = dui.front().y + y[i];
			if (can(tmp) && a[tmp.x][tmp.y]==-1) {
				a[tmp.x][tmp.y] = time + 1;
				dui.push(tmp);
			}
		}
		dui.pop();
	}
	for (i = 1; i <= nx; i++) {
		for (j = 1; j <= ny; j++) printf("%-5d", a[i][j]);//cout << setw(5) << setiosflags(ios::left) << a[i][j] << " ";
		printf("\n");//cout << setw(5) << setiosflags(ios::left) << a[i][ny] << endl;
	}
}
