#include <windows.h>
#include <ctime>
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <set>
using namespace std;
set<int> mk;
char pri[51][51];
bool rec[51][51];
int h, w, n,mark;
const int xp[] = { -1,-1,0,1,1,1,0,-1 }, yp[] = { 0,1,1,1,0,-1,-1,-1 };
void init() {
	cout << "——————扫雷v0.01	xa制作——————" << endl;
	system("pause");
	system("cls");
	cout << "请输入棋盘大小" << endl;
	cout << "高：";
	cin >> h;
	cout << "宽：";
	cin >> w;
	do {
		cout << "请输入雷数：";
		cin >> n;
		if (n <= 0 && n >= h*w) printf("雷数不符合规则!请输入1-%d间的一个整数", h*w-1);
	} while (n <= 0 || n >= h*w);
	cout << "tips:(1,1)永远不是雷哦" << endl;
	cout << "加载中...(其实并不需要加载，只是让你看到上面这条tips罢了= =)" << endl;
	Sleep(1000);
	memset(rec, 0, sizeof(rec));
	mk.erase(mk.begin(), mk.end());
	for (int i = 0; i < n; i++) {
		int x = (rand() % h)+1;
		int y = (rand() % w)+1;
		if (!(x == 1 && y == 1) && !rec[x][y]) rec[x][y] = 1;
		else i--;
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			pri[i][j] = '#';
		}
	}
}
void display() {
	printf("   ");
	for (int i = 1; i <= w; i++) printf("  %d", i);
	printf("\n");
	printf("\n");
	for (int i = 1; i <= h; i++) {
		printf("%2d ", i);
		for (int j = 1; j <= w; j++) {
			printf("  %c", pri[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
void gameover() {
	system("cls");
	display();
	cout << "!!!!!!!!!!!!!Game Over!!!!!!!!!!!!!" << endl;
	cout << "你想要再来一盘么?(Y/N)：";
	int ch;
	cin >> ch;
	system("cls");
	if (ch == 'N')  exit(0);
	return;
}
void youwin() {
	system("cls");
	display();
	cout << "!!!!!!!!!!!!!You Win!!!!!!!!!!!!!" << endl;
	cout << "你想要再来一盘么?(Y/N)：";
	int ch;
	cin >> ch;
	system("cls");
	if (ch == 'N')  exit(0);
	return;
}
int click(int x,int y) {
	if (rec[x][y]) {
		for (int i = 1; i <= h; i++)
			for (int j=1;j<=w;j++)
				if (rec[i][j]) pri[i][j] = '@';
		gameover();
		return 233;
	}
	bool m[51][51];
	memset(m, 0, sizeof(m));
	m[x][y] = 1;
	queue<int> quex;
	queue<int> quey;
	quex.push(x);
	quey.push(y);
	while (!quex.empty()) {
		int num = 0, x1 = quex.front(), y1 = quey.front();
		for (int i = 0; i < 8; i++)
			if (rec[x1 + xp[i]][y1 + yp[i]]) num++;
		if (num==0){
			for (int i = 0; i < 8; i ++) {
				int xx = x1 + xp[i], yy = y1 + yp[i];
				if (xx > 0 && xx <= h && yy > 0 && yy <= w && !m[xx][yy] && !rec[xx][yy]) {
					m[xx][yy] = 1;
					quex.push(xx); 
					quey.push(yy);
				}
			}
			pri[x1][y1] = ' ';
		}
		else pri[x1][y1] = char((int)'0' + num);
		quex.pop();
		quey.pop();
	}
	return 0;
}
int sign(int x,int y) {
	if (pri[x][y] != '#' && pri[x][y] != '!' ) {
		cout << "错误！你不能标记在这！" << endl;
		return 0;
	}
	if (pri[x][y] == '#') {
		pri[x][y] = '^';
		mark++;
		if (!rec[x][y]) mk.insert((x - 1)*w + y);
	}
	else {
		if (pri[x][y] == '^') {
			pri[x][y] = '#';
			mark--;
			if (!rec[x][y]) mk.erase((x - 1)*w + y);
		}
	}
	if (mark == n && mk.empty()) {
		youwin();
		return 233;
	}
	return 0;
}
int play() {
	system("cls");
	while (1) {
		char rd;
		system("cls");
		display();
		printf("请输入操作（q:退出，f:标记雷，r:重置游戏，i:点击坐标）：");
		cin >> rd;
		switch (rd) {
			case 'i': {
				int x, y, t;
				do {
					printf("请输入坐标：");
					cin >> x >> y;
					if (x <= 0 || x > h || y <= 0 || y > w) printf("输入格式错误！");
				} while (x <= 0 || x > h || y <= 0 || y > w);
				t=click(x, y);
				if (t == 233) return t;
			} break;
			case 'q':exit(0); break;
			case 'f': {
				int x, y, t;
				do {
					printf("请输入坐标：");
					cin >> x >> y;
					if (x <= 0 || x > h || y <= 0 || y > w) printf("输入格式错误！");
				} while (x <= 0 || x > h || y <= 0 || y > w);
				t = sign(x, y);
				if (t == 233) return t;
			} break;
			case 'r':return 233; break;
			case 'B':youwin(); break;
			default: {
				printf("输入格式错误！");
				string tmp;
				getline(cin, tmp);
				continue;
			}
		}
	}
	return 0;
}
int main() {
	int t;
game_begin:
	system("cls");
	srand((unsigned)time(0));
	init();
	t=play();
	if (t == 233) goto game_begin;
	return 0;
}