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
#include<list>
#include<iostream>
using namespace std;
const int ColumnMax = 5;
const int RowMax = 8;
int n;

template <class T>
class MyList {
	class Node {
		T v;
		
	}
public:

};


class Block {
public:
	int ColorID = 0;
	Block(int color) : ColorID(color) {}
	static void Swap(Block* a, Block* b) {
		int tmp = a->ColorID;
		a->ColorID = b->ColorID;
		b->ColorID = tmp;
	}
};

class Column {
	Block* List[RowMax];
	list<Block*> ErasableList;
public:
	list<Block*> CheckErasable() {
		ErasableList.clear();
		int LastColor = 0, Total = 0;
		for (int i = 0; i < RowMax; i++) {
			Block* b = List[i];
			if (b->ColorID == LastColor) Total++;
			else {
				Total = 1;
				LastColor = b->ColorID;
				for (int j = i; j > i - Total; j--) {
					ErasableList.push_back(List[j]);
				}
			}
		}
		return ErasableList;
	}
	void Fall() {
		int RealRow = 0;
		for (int i = 0; i < RowMax; i++) {
			Block* b = List[i];
			if (b->ColorID == 0) continue;
			if (i != RealRow) List[RealRow]->ColorID = List[i]->ColorID;
			RealRow++;
		}
		for (int i = RealRow; i < RowMax; i++) {
			Block* b = List[i];
			b->ColorID = 0;
		}
	}
};

class Row {
	Block* List[ColumnMax];
	list<Block*> ErasableList;
public:
	list<Block*> CheckErasable() {
		ErasableList.clear();
		int LastColor = 0, Total = 0;
		for (int i = 0; i < ColumnMax; i++) {
			Block* b = List[i];
			if (b->ColorID == LastColor) Total++;
			else {
				Total = 1;
				LastColor = b->ColorID;
				for (int j = i; j > i - Total; j--) {
					ErasableList.push_back(List[j]);
				}
			}
		}
		return ErasableList;
	}
};

class ChessBoard {
	Block Board[ColumnMax][RowMax];
	Row Rows[RowMax];
	Column Columns[ColumnMax];
	void ReFresh() {
		for (int i = 0; i < ColumnMax; i++) {
			Columns[i].Fall();
		}
	}
	void Erease() {
		while (1) {
			list<Block*> EreaseList;
			EreaseList.clear();
			for (int i = 0; i < ColumnMax; i++) {
				EreaseList.splice(EreaseList.begin(), Columns[i].CheckErasable());
			}
			for (int i = 0; i < RowMax; i++) {
				EreaseList.splice(EreaseList.begin(), Rows[i].CheckErasable());
			}
			if (EreaseList.empty()) break;
			for (list<Block*>::iterator it = EreaseList.begin(); it != EreaseList.end(); it++) {
				(*it)->ColorID = 0;
			}
			ReFresh();
		}
	}
public:
	void Init() {
		for (int i = 0, j = 0, tmp; i < ColumnMax; i++) {
			scanf("%d", &tmp);
			while (tmp && j < RowMax) {
				Board[i][j].ColorID = tmp;
				scanf("%d", &tmp);
			}
		}
	}

};