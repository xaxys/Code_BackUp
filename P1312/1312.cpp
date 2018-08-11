/*
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int n;
vector<int> g[5];
int dx[10], dy[10], dir[10], f;
void putscr(int x) {
	fprintf(stderr, "Depth : %d\n", x);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			fprintf(stderr, "%4d", g[i][j]);
		}
		fprintf(stderr, "\n");
	}
}
void xiaochu(int x, int y) {
	if (g[x].size() <= y) return;
	int col = g[x][y];
	int miny = y, maxy = y + 1;
	while (miny > 0 && g[x][miny - 1] == col) miny--;
	while (maxy < g[x].size() && g[x][maxy] == col) maxy++;
	if (maxy - miny >= 3) {
		g[x].erase(g[x].begin() + miny, g[x].begin() + maxy);
		for (int i = miny; i < maxy; i++) xiaochu(x, i);
		return;
	}
	int minx = x, maxx = x + 1;
	while (minx > 0 && g[minx - 1].size() > y && g[minx - 1][y] == col) minx--;
	while (maxx < 5 && g[maxx].size() > y && g[maxx][y] == col) maxx++;
	if (maxx - minx >= 3) {
		for (int i = minx; i < maxx; i++) g[i].erase(g[i].begin() + y);
		for (int i = minx; i < maxx; i++) xiaochu(i, y);
		return;
	}
}
inline bool isok() {
	return g[0].empty() && g[1].empty() && g[2].empty() && g[3].empty() && g[4].empty();
}
void dfs(int x) {
	//putscr(x);
	if (x > n) return;
	vector<int> copy[5];
	for (int i = 0; i < 5; i++) copy[i] = g[i];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if (i < 4 && g[i + 1].size() > j) {
				swap(g[i][j], g[i + 1][j]);
				dx[x] = i; dy[x] = j; dir[x] = 1;
				xiaochu(i, j);
				xiaochu(i + 1, j);
				if (isok() && x == n - 1) {
					f = 1;
					return;
				}
				dfs(x + 1);
				if (f) return;
				for (int i = 0; i < 5; i++) g[i] = copy[i];
			}
			else if (i < 4) {
				int yy = g[i + 1].size();
				g[i + 1].push_back(g[i][j]);
				g[i].erase(g[i].begin() + j);
				dx[x] = i; dy[x] = j; dir[x] = 1;
				xiaochu(i, j);
				xiaochu(i + 1, yy);
				if (isok() && x == n - 1) {
					f = 1;
					return;
				}
				dfs(x + 1);
				if (f) return;
				for (int i = 0; i < 5; i++) g[i] = copy[i];
			}
			if (i) {
				int yy = g[i - 1].size();
				g[i - 1].push_back(g[i][j]);
				g[i].erase(g[i].begin() + j);
				dx[x] = i; dy[x] = j; dir[x] = -1;
				xiaochu(i, j);
				xiaochu(i - 1, yy);
				if (isok() && x == n - 1) {
					f = 1;
					return;
				}
				dfs(x + 1);
				if (f) return;
				for (int i = 0; i < 5; i++) g[i] = copy[i];
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	int rd;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= 7; j++) {
			scanf("%d", &rd);
			if (!rd) break;
			g[i].push_back(rd);
		}
	}
	dfs(0);
	if (f) {
		for (int i = 0; i < n; i++) 
			printf("%d %d %d\n", dx[i], dy[i], dir[i]);
	}
	else printf("-1\n");
	return 0;
}
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int n;
vector<int> g[5];
int dx[10], dy[10], dir[10], f;
void putscr(int x) {
	fprintf(stderr, "Depth : %d\n", x);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			fprintf(stderr, "%4d", g[i][j]);
		}
		fprintf(stderr, "\n");
	}
}
void xiaochu(int x, int y) {
	if (g[x].size() <= y) return;
	int col = g[x][y];
	int miny = y, maxy = y + 1;
	while (miny > 0 && g[x][miny - 1] == col) miny--;
	while (maxy < g[x].size() && g[x][maxy] == col) maxy++;
	if (maxy - miny >= 3) {
		g[x].erase(g[x].begin() + miny, g[x].begin() + maxy);
		for (int i = miny; i < maxy; i++) xiaochu(x, i);
		return;
	}
	int minx = x, maxx = x + 1;
	while (minx > 0 && g[minx - 1].size() > y && g[minx - 1][y] == col) minx--;
	while (maxx < 5 && g[maxx].size() > y && g[maxx][y] == col) maxx++;
	if (maxx - minx >= 3) {
		for (int i = minx; i < maxx; i++) g[i].erase(g[i].begin() + y);
		for (int i = minx; i < maxx; i++) xiaochu(i, y);
		return;
	}
}
inline bool isok() {
	return g[0].empty() && g[1].empty() && g[2].empty() && g[3].empty() && g[4].empty();
}
void dfs(int x) {
	//putscr(x);
	if (x > n) return;
	vector<int> copy[5];
	for (int i = 0; i < 5; i++) copy[i] = g[i];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if (i < 4 && g[i + 1].size() > j) {
				swap(g[i][j], g[i + 1][j]);
				dx[x] = i; dy[x] = j; dir[x] = 1;
				xiaochu(i, j);
				xiaochu(i + 1, j);
				if (isok() && x == n - 1) {
					f = 1;
					return;
				}
				dfs(x + 1);
				if (f) return;
				for (int i = 0; i < 5; i++) g[i] = copy[i];
			}
			else if (i < 4) {
				int yy = g[i + 1].size();
				g[i + 1].push_back(g[i][j]);
				g[i].erase(g[i].begin() + j);
				dx[x] = i; dy[x] = j; dir[x] = 1;
				xiaochu(i, j);
				xiaochu(i + 1, yy);
				if (isok() && x == n - 1) {
					f = 1;
					return;
				}
				dfs(x + 1);
				if (f) return;
				for (int i = 0; i < 5; i++) g[i] = copy[i];
			}
			if (i) {
				int yy = g[i - 1].size();
				g[i - 1].push_back(g[i][j]);
				g[i].erase(g[i].begin() + j);
				dx[x] = i; dy[x] = j; dir[x] = -1;
				xiaochu(i, j);
				xiaochu(i - 1, yy);
				if (isok() && x == n - 1) {
					f = 1;
					return;
				}
				dfs(x + 1);
				if (f) return;
				for (int i = 0; i < 5; i++) g[i] = copy[i];
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	int rd;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= 7; j++) {
			scanf("%d", &rd);
			if (!rd) break;
			g[i].push_back(rd);
		}
	}
	dfs(0);
	if (f) {
		for (int i = 0; i < n; i++)
			printf("%d %d %d\n", dx[i], dy[i], dir[i]);
	}
	else printf("-1\n");
	return 0;
}