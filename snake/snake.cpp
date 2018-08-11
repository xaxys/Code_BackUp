#pragma execution_character_set("utf-8")
#include <iostream>
#include <list>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <conio.h>
#include <windows.h>
using namespace std;

class Node {
public:
	int x, y;
	Node(int x1, int y1);
};

class UserData {
public:
	string name;
	long long score;
	int gt;
	int gr;
	UserData(string s, long long sc, int gametime, int grade);
	friend bool operator < (UserData a, UserData b);
};

#define RIGHT 0x4d
#define LEFT 0x4b  
#define UP 0x48  
#define DOWN 0x50 
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define ORANGE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define PURPLE FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define RED  FOREGROUND_RED | FOREGROUND_INTENSITY
const int STARTX = 8;
const int STARTY = 4;
const int RANGEX = 60;
const int RANGEY = 20;
int point = 10;
const int ENDX = STARTX + RANGEX;
const int ENDY = STARTY + RANGEY;
bool isSnake[RANGEY + 10][RANGEX + 10];
int speed;
int sysj;
int gametime;
list<Node> snake;
int curDiraction; //�ߵĵ�ǰǰ������, 1��, 2��, 3��, 4��
int score; //��ǰ����
int grade;
int snakeLen; //�ߵĳ���
int foodx, foody; //ʳ������
int gox, goy; //��ͷ����
int mj;
void GoTo(short x, short y); //��λ���
void DrawBoard(); //���Ʊ߿�
void ShowInformation(); //չʾ��Ϸ��Ϣ
void Init(); //��ʼ����Ϸ
void RunSnake(int x, int y); //��������
void Try(int& x, int& y); //����
bool IsGoodCoord(int x, int y); //ǰ�������Ƿ�Ϸ�
void AddFood(); //����ʳ��
void EartFood(); //��ʳ��
void InitSnake(); //��ʼ������
bool EndGame(); //������Ϸ
bool StartGame(); //������Ϸ
bool GameMenu(); //��Ϸ�˵�
void ShowRanking(); //���а�
void ShowAbout(); //�����Ϣ
void InputData(); //�����������

int main() {
	while (true) {
		if (!GameMenu()) return 0;
	}
	return 0;
}

Node::Node(int x1, int y1) { //����Node����
	x = x1; y = y1;
}

bool operator < (UserData a, UserData b) { //������������������ɴ�С����
	if (a.score != b.score)
		return a.score > b.score;
	if (a.gt != b.gt)
		return a.gt > b.gt;
	else
		return a.gr > b.gr;
}
UserData::UserData(string s, long long sc, int gametime_, int _grade) { //����UserData����
	name = s; score = sc; gt = gametime_; gr = _grade;
}

void color(WORD A)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), A);
}

void Color(int score_)
{
	if (score_ % 4 == 1)
	{
		color(PURPLE);
	}
	else if (score_ % 4 == 2)
	{
		color(RED);
	}
	else if (score_ % 4 == 3)
	{
		color(YELLOW);
	}
	else if (score_ % 4 == 0)
	{
		color(CYAN);
	}
}

void GoTo(short x, short y) { //��λ���
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowInformation() { //�����Ϸ��Ϣ
	color(YELLOW);
	GoTo(78, 5);
	printf("̰������Ϸ");
	GoTo(78, 18);
	gametime = (clock() - mj) / 1000;
	grade = snakeLen - 3;
	printf("����ʱ�䣺%3d ��", (clock() - mj) / 1000);
	GoTo(78, 8);
	printf("��Ϸ����");
	GoTo(78, 10);
	printf("�밴 �� �� �� ��  �����������߳Զ���");
	GoTo(78, 12);
	printf("�Ե�Խ�࣬�߾�Խ�������ĵȼ�Ҳ��Խ��");
	GoTo(78, 14);
	printf("���߳Ե��Լ���ײ��ǽʱ����Ϸ������");
	GoTo(78, 16);
	printf("�Զ�ǰ��ʱ�䣺%3dms", speed);
	GoTo(78, 20);
	printf("��ǰ�ȼ��� %8d", snakeLen - 3);
	GoTo(78, 23);
	printf("���ķ����� %d", score);
	color(CYAN);
	printf("+%d=%d", score / 3, score * 3 / 2);
	color(YELLOW);
	GoTo(78, 25);
	printf("ʣ��ʱ�䣺%d��", 10 + (snakeLen - 3) * 4 - gametime);
	sysj = 10 + (snakeLen - 3) * 4 - gametime;
}

void DrawBoard() { //����ǽ��

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //���������

	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 }; //�����Ϣ
	SetConsoleCursorInfo(hOut, &cursor_info); //���ع��

	COORD size = { 120, 30 };
	SetConsoleScreenBufferSize(hOut, size); //���軺������С

	SMALL_RECT rc = { 0 , 0, 120, 30 };
	SetConsoleWindowInfo(hOut, true, &rc); //���贰�ڴ�С

	SetConsoleTextAttribute(hOut, CYAN);

	for (int i = STARTX - 2; i <= ENDX + 2; i += 2) { //����ǽ��
		GoTo(i, STARTY - 1);
		printf("��");
		GoTo(i, ENDY + 1);
		printf("��");
	}
	for (int i = STARTY - 1; i <= ENDY + 1; ++i) { //����ǽ��
		GoTo(STARTX - 2, i);
		printf("��");
		GoTo(ENDX + 2, i);
		printf("��");
	}
}
void draw()
{
	char m = snakeLen + 62;
	Color(score);
	cout << "��";
}
void Init() { //��ʼ����Ϸ
	system("cls");
	memset(isSnake, 0, sizeof(isSnake));
	speed = 200;
	curDiraction = 4;
	score = 0;
	DrawBoard();
	InitSnake();
	ShowInformation();
	AddFood();
	mj = clock();
	point = 10;
	sysj = 10;
}

void RunSnake(int x, int y) { //��������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	score += snakeLen + 1;
	if (x == foodx && y == foody) {
		EartFood();
		AddFood();
		return;
	}
	snake.push_front(Node(x, y));
	isSnake[y][x] = true;
	GoTo(x, y);
	draw();
	Node back = snake.back();
	snake.pop_back();
	isSnake[back.y][back.x] = false;
	GoTo(back.x, back.y);
	printf(" ");
}

void Try(int& x, int& y) { //����
	int key, cnt = 100;
	while (cnt--) { //��μ�����״̬
		if (_kbhit()) {
			key = getch();
			switch (key) {
			case UP:
				if (curDiraction == 1 || curDiraction == 2) break;
				--y; curDiraction = 1; return;
			case DOWN:
				if (curDiraction == 1 || curDiraction == 2) break;
				++y; curDiraction = 2; return;
			case LEFT:
				if (curDiraction == 3 || curDiraction == 4) break;
				x -= 2; curDiraction = 3; return;
			case RIGHT:
				if (curDiraction == 3 || curDiraction == 4) break;
				x += 2; curDiraction = 4; return;
			}
		}
	}
	if (curDiraction == 1) --y; //�û�û������ʱ
	else if (curDiraction == 2) ++y;
	else if (curDiraction == 3) x -= 2;
	else x += 2;
}

bool IsGoodCoord(int x, int y) { //�жϹ���Ƿ�Ϸ�
	if (x <= ENDX && y <= ENDY && x >= STARTX && y >= STARTY)
		return true;
	else
		return false;
}

void AddFood() { //����ʳ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PURPLE);
	srand((unsigned)time(NULL));
	while (true) {
		foodx = (rand() % ENDX) + 1;
		foody = (rand() % ENDY) + 1;
		if (foodx & 1) foodx++;
		if (!isSnake[foody][foodx] && IsGoodCoord(foodx, foody)) break;
	}
	GoTo(foodx, foody);
	int a = rand() % 5;
	if (a >= 4)
		printf("��");
	else if (a <= 1)
		printf("��");
	else
		printf("��");
}

void EartFood() { //�Զ���
	point += 4;
	int sb = gametime = (clock() - mj) / 1000;
	sysj = point - sb;
	score += score / 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	snake.push_front(Node(foodx, foody));
	isSnake[foody][foodx] = true;
	++snakeLen;
	if (speed >= 55) speed -= 5;

	GoTo(foodx, foody);
	draw();
	AddFood();
}

void InitSnake() { //��ʼ������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	snakeLen = 3, gox = 18, goy = 14;
	snake.clear();
	snake.push_front(Node(12, 14));
	snake.push_front(Node(14, 14));
	snake.push_front(Node(16, 14));
	for (int i = 12; i <= 16; i += 2) {
		GoTo(i, 14);
		draw();
		isSnake[14][i] = true;
	}
}
bool EndGame() { //������Ϸ
	system("cls");
	DrawBoard();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	GoTo(28, 10);
	printf("���ı�����Ϸ�÷֣� %d��", score);
	GoTo(32, 18);
	printf("....�����....");
	GoTo(27, 20);
	printf("�Ƿ������Ϸ: ��(1), ��(0)");
	GoTo(27, 22);
	char key = getch();
	while (true) {
		if (key == '1') return false;
		else if (key == '0')
		{
			GoTo(ENDX + 1, ENDY + 2);
			exit(0); return true;
		}
		else key = getch();
	}
}

bool StartGame() { //������Ϸ

	Init();

	while (IsGoodCoord(gox, goy) && !isSnake[goy][gox] && sysj>0) { //�����ߺϷ�ʱ
		RunSnake(gox, goy);
		ShowInformation();
		Try(gox, goy);
		Sleep(speed);
	}
	InputData();
	return true;
}

bool GameMenu() { //��Ϸ�˵�
	system("cls");
	DrawBoard();
	GoTo(STARTX + 22, STARTY + 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	printf("��ӭ����̰������Ϸ!");
	GoTo(STARTX + 24, STARTY + 10);
	printf("1: ����Ϸ");
	GoTo(STARTX + 24, STARTY + 12);
	printf("2: ���а�");
	GoTo(STARTX + 24, STARTY + 14);
	printf("3: ������Ϸ");
	GoTo(STARTX + 24, STARTY + 16);
	printf("4: �˳���Ϸ");

	while (true) {
		if (_kbhit()) {
			char key = getch();
			switch (key) {
			case '1':
				if (!StartGame()) return false;
				else return true;
			case '2':
				ShowRanking(); return true;
			case '3':
				ShowAbout(); return true;
			case '4':
				GoTo(1, ENDY + 2);
				return false;
			default:
				return true;
			}
		}
	}
}

void ShowRanking() { //չʾ���а�
	vector<UserData> vu;
	FILE *fp = fopen("GameData.txt", "r");
	if (fp == NULL) fp = fopen("GameData.txt", "w+");
	char name[20];
	int len = 0;
	while (fscanf(fp, "%s", name) != EOF) {
		++len;
		int score, g = grade;
		fscanf(fp, "%d%d%d%*c", &score, &gametime, &g);
		vu.push_back(UserData(string(name), score, gametime, grade));
	}
	fclose(fp);
	sort(vu.begin(), vu.end()); //�Ե÷ֽ�������
	system("cls");
	DrawBoard();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
	GoTo(STARTX + 8, STARTY + 2);
	printf("�û�");
	GoTo(STARTX + 20, STARTY + 2);
	printf("����");
	GoTo(STARTX + 32, STARTY + 2);
	printf("����ʱ��");
	GoTo(STARTX + 44, STARTY + 2);
	printf("����");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);

	for (int i = 0; i < len && i < 10; ++i) { //��ӡǰʮ���û�����
		char const *p = vu[i].name.c_str();
		Color(vu[i].score);
		GoTo(STARTX + 8, STARTY + 4 + i);
		printf("%s", p);
		GoTo(STARTX + 20, STARTY + 4 + i);
		printf("%d��", vu[i].score);
		GoTo(STARTX + 32, STARTY + 4 + i);
		printf("%d��", vu[i].gt);
		GoTo(STARTX + 44, STARTY + 4 + i);
		printf(" %d", i + 1);
	}

	GoTo(STARTX + 4, ENDY - 2);
	printf("-----------------  ��'1'������Ϸ�˵�  ---------------");
	while (true) {
		if (_kbhit()) {
			char key = getch();
			if (key == '1') break;
		}
	}
}

void ShowAbout() { //չʾ��Ϸ���
	system("cls");
	DrawBoard();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);

	GoTo(STARTX + 4, STARTY + 2);
	printf("-------------------  ̰������Ϸ  -------------------");
	GoTo(STARTX + 10, STARTY + 4);
	printf("������: ");
	GoTo(STARTX + 10, STARTY + 6);
	printf("000");
	GoTo(STARTX + 10, STARTY + 8);
	printf("̰������Ϸ");
	GoTo(STARTX + 10, STARTY + 10);
	printf("��Ϸ����");
	GoTo(STARTX + 10, STARTY + 12);
	printf("�밴 �� �� �� ��  �����������߳Զ���");
	GoTo(STARTX + 10, STARTY + 14);
	printf("�Ե�Խ�࣬�߾�Խ�������ĵȼ�Ҳ��Խ��");
	GoTo(STARTX + 10, STARTY + 16);
	printf("���߳Ե��Լ���ײ��ǽʱ����Ϸ������");

	GoTo(STARTX + 4, ENDY - 2);
	printf("-----------------  ��'1'������Ϸ�˵�  ---------------");
	while (true) {
		if (_kbhit()) {
			char key = getch();
			if (key == '1') break;
		}
	}
}

void InputData() { //�û���������
	char name[20];
	if (score >= 1000)
	{
		GoTo(STARTX + 10, STARTY + 10);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printf("�������������: ");
		COORD coord = { STARTX + 10, STARTY + 12 };
		SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), coord);
		while (true) { //���ԷǷ��ַ�
			scanf("%s", name);
			if (name[0] != 0 && name[0] != ' ') break;
		}FILE *fp = fopen("Gamedata.txt", "a");
		if (fp == NULL) fp = fopen("GameData.txt", "w+");
		fprintf(fp, "%s %d %d \n", name, score, gametime);
		fclose(fp);
	}
	else
	{
		GoTo(STARTX + 20, STARTY + 10);
		cout << "Ӵ�������Ҳ���ϰ񣿣�" << endl;
		Sleep(1000);
	}
	EndGame();

}