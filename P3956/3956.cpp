#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
int n, m, c[110][110], ans[110][110];
static const int dx[] = { 0,1,0,-1 }, dy[] = { -1,0,1,0 };
void dfs(int x, int y, int cost, int color) {
	if (cost >= ans[x][y]) return;
	ans[x][y] = cost;
	if (x == m && y == m) return;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 1 && nx <= m && ny >= 1 && ny <= m) {
			if (color) {
				if (c[nx][ny] == 0) continue;
				else if (c[nx][ny] == color) dfs(nx, ny, cost, 0);
				else dfs(nx, ny, cost + 1, 0);
			}
			else {
				if (c[nx][ny] == 0) dfs(nx, ny, cost + 2, c[x][y]);
				else if (c[nx][ny] == c[x][y]) dfs(nx, ny, cost, 0);
				else dfs(nx, ny, cost + 1, 0);
			}
		}
	}
}
int main() {
	memset(c, 0, sizeof(c));
	memset(ans, 0x7f, sizeof(ans));
	cin >> m >> n;
	while (n--) {
		int x, y, z;
		cin >> x >> y >> z;
		c[x][y] = z + 1;
	}
	dfs(1, 1, 0, 0);
	int _out = ans[m][m] < 2100000000 ? ans[m][m] : -1;
	cout << _out << endl;
	return 0;
}