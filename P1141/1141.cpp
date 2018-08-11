#include <iostream>
#include <queue>
#include <string.h>
#include <string>
using namespace std;
class point {
public:
	int x, y;
};
int n, m, b[1010][1010], c[1000000];
bool a[1010][1010];
queue<point> dui;
const int x[] = { 0,1,0,-1 }, y[] = { 1,0,-1,0 };
int main() {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	cin >> n >> m;
	point tmp;
	int i, j, k = 1;
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			char rd;
			cin >> rd;
			if (rd == '1') a[i][j] = 1;
		}
	}
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++) {
			if (b[i][j] == 0) {
				tmp.x = i; tmp.y = j;
				b[tmp.x][tmp.y] = k;
				dui.push(tmp);
				while (!dui.empty()) {
					bool q = a[dui.front().x][dui.front().y];
					for (int p = 0; p<4; p++) {
						tmp.x = dui.front().x + x[p];
						tmp.y = dui.front().y + y[p];
						if (tmp.x<n&&tmp.x >= 0 && tmp.y<n&&tmp.y >= 0 && a[tmp.x][tmp.y] != q && b[tmp.x][tmp.y] == 0) {
							b[tmp.x][tmp.y] = k;
							dui.push(tmp);
						}
					}
					dui.pop();
					c[k]++;
				}
				k++;
			}
		}
	for (i = 0; i < m; i++) {
		int inx, iny;
		cin >> inx >> iny;
		cout << c[b[inx-1][iny-1]] << endl;
	}
	return 0;
}
