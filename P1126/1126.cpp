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
	int x, y, from, depth;//��¼ÿ��������ʱ���ꡢ���������ʱ��
};

const int x[] = { 1,0,-1,0 }, y[] = { 0,-1,0,1 };//���from�ĸ����򣬽����������˵��ж�·�ߣ�������θı䣩
int n, m, sx, sy, ex, ey, sfrom,a[60][60];//sx,syΪ������� ex,eyΪ�յ����� sfromΪ������Դ���򣨼��������泯�����෴�� aΪ��ͼ�ļ�¼
bool b[60][60][4];//��¼��ͼ��ÿ�����ĸ������ѹ�û��
queue<pos> dui;//����
//��ת
int left(int from) {
	if (from == 0) return 3;
	return (from - 1);
}
//��ת
int right(int from) {
	if (from == 3) return 0;
	return (from + 1);
}
//���Ի����ܷ���ǰ��i�����ܣ�ͬʱ��b�м�¼
bool can(pos tmp, int i) {
	tmp.x += x[tmp.from] * i;
	tmp.y += y[tmp.from] * i;
	if (tmp.x >= 1 && tmp.x < n && tmp.y >= 1 && tmp.y < m && a[tmp.x][tmp.y] == 0 && a[tmp.x + 1][tmp.y] == 0 && a[tmp.x][tmp.y + 1] == 0 && a[tmp.x + 1][tmp.y + 1] == 0 && !b[tmp.x][tmp.y][tmp.from]) {
		b[tmp.x][tmp.y][tmp.from] = 1;
		return 1;
	}
	return 0;
}
//������
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
		case 'N':sfrom = south; break;  //fromΪ��Դ����Ӧ�볯���෴
		case 'E':sfrom = west; break;
		case 'W':sfrom = east; break;
	}
	pos tmp = { sx,sy,sfrom,0 };
	b[sx][sy][sfrom] = 1;
	dui.push(tmp);
	while (!dui.empty()) {
		//�����ֱ���˳�
		if (dui.front().x == ex&&dui.front().y == ey) {
			cout << dui.front().depth << endl;
			return 0;
		}
		//��ת
		tmp = dui.front();
		tmp.depth += 1;
		tmp.from = left(tmp.from);
		if (!b[tmp.x][tmp.y][tmp.from]) {
			dui.push(tmp);
			b[tmp.x][tmp.y][tmp.from] = 1;
		}
		//��ת
		tmp = dui.front();
		tmp.depth += 1;
		tmp.from = right(tmp.from);
		if (!b[tmp.x][tmp.y][tmp.from]) {
			dui.push(tmp);
			b[tmp.x][tmp.y][tmp.from] = 1;
		}
		//ֱ��
		tmp = dui.front();
		tmp.depth += 1;
		i = 1;
		while (i < 4){
			if (can(tmp, i)) {        //�������ֱ��i������һ�����
				pos k = tmp;
				k.x += x[tmp.from] * i;
				k.y += y[tmp.from] * i;
				dui.push(k);
				i++;
			}
			else break;               //����������ǰ�ߣ��˳�����
		}
		//������ϳ���
		dui.pop();
	}
	cout << "-1" << endl;
	return 0;
}