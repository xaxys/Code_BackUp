#include <iostream>
#include <queue>
#include <string.h>
#define north 0
#define east 1
#define south 2
#define west 3
using namespace std;

class pos {
public:
	int x, y, from, depth;//记录每个点搜索时坐标、方向和所需时间
};

const int x[] = { 1,0,-1,0 }, y[] = { 0,-1,0,1 };//针对from四个方向，接下来机器人的行动路线（坐标如何改变）
int n, m, sx, sy, ex, ey, sfrom,a[60][60];//sx,sy为起点坐标 ex,ey为终点坐标 sfrom为机器来源方向（即与读入的面朝方向相反） a为地图的记录
bool b[60][60][4];//记录地图上每个点四个方向搜过没有
queue<pos> dui;//队列
//左转
int left(int from) {
	if (from == 0) return 3;
	return (from - 1);
}
//右转
int right(int from) {
	if (from == 3) return 0;
	return (from + 1);
}
//测试机器能否向前走i格，若能，同时在b中记录
bool can(pos tmp, int i) {
	tmp.x += x[tmp.from] * i;
	tmp.y += y[tmp.from] * i;
	if (tmp.x >= 1 && tmp.x < n && tmp.y >= 1 && tmp.y < m && a[tmp.x][tmp.y] == 0 && a[tmp.x + 1][tmp.y] == 0 && a[tmp.x][tmp.y + 1] == 0 && a[tmp.x + 1][tmp.y + 1] == 0 && !b[tmp.x][tmp.y][tmp.from]) {
		b[tmp.x][tmp.y][tmp.from] = 1;
		return 1;
	}
	return 0;
}
//主程序
int main() {
	int i, j;
	char rd;
	memset(b, 0, sizeof(b));
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	for (j = 1; j <= m; j++)
		cin >> a[i][j];
	cin >> sx >> sy >> ex >> ey >> rd;
	switch (rd){
		case 'S':sfrom = north; break;
		case 'N':sfrom = south; break;  //from为来源方向，应与朝向相反
		case 'E':sfrom = west; break;
		case 'W':sfrom = east; break;
	}
	pos tmp = { sx,sy,sfrom,0 };
	b[sx][sy][sfrom] = 1;
	dui.push(tmp);
	while (!dui.empty()) {
		//若到达，直接退出
		if (dui.front().x == ex&&dui.front().y == ey) {
			cout << dui.front().depth << endl;
			return 0;
		}
		//左转
		tmp = dui.front();
		tmp.depth += 1;
		tmp.from = left(tmp.from);
		if (!b[tmp.x][tmp.y][tmp.from]) {
			dui.push(tmp);
			b[tmp.x][tmp.y][tmp.from] = 1;
		}
		//右转
		tmp = dui.front();
		tmp.depth += 1;
		tmp.from = right(tmp.from);
		if (!b[tmp.x][tmp.y][tmp.from]) {
			dui.push(tmp);
			b[tmp.x][tmp.y][tmp.from] = 1;
		}
		//直行
		tmp = dui.front();
		tmp.depth += 1;
		i = 1;
		while (i < 4){
			if (can(tmp, i)) {        //如果可以直行i格，则下一格入队
				pos k = tmp;
				k.x += x[tmp.from] * i;
				k.y += y[tmp.from] * i;
				dui.push(k);
				i++;
			}
			else break;               //否则不能再往前走，退出搜索
		}
		//搜索完毕出队
		dui.pop();
	}
	cout << "-1" << endl;
	return 0;
}