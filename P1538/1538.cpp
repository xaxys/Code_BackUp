#include<iostream>
#include<string>
using namespace std;
const int m[7][11] = {
	{ 1,0,1,1,0,1,1,1,1,1 },//上0
	{ 1,0,0,0,1,1,1,0,1,1 },//上左1
	{ 1,1,1,1,1,0,0,1,1,1 },//上右2
	{ 0,0,1,1,1,1,1,0,1,1 },//中3
	{ 1,0,1,0,0,0,1,0,1,0 },//下左4
	{ 1,1,0,1,1,1,1,1,1,1 },//下右5
	{ 1,0,1,1,0,1,1,0,1,1 }//下6
};
int k, num[256];
string s;
int main(int argc, char **argv) {
	cin >> k >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) num[i] = s[i] ^ 48;
	for (int i = 0; i < len; i++) {//上
		cout << " ";
		for (int j = 0; j < k; j++) cout << (m[0][num[i]] == 0 ? " " : "-");
		cout << "  ";
	}
	cout << endl;
	for (int t = 0; t < k; t++) {//上左上右
		for (int i = 0; i < len; i++) {
			cout << (m[1][num[i]] == 0 ? " " : "|");
			for (int j = 0; j < k; j++) cout << " ";
			cout << (m[2][num[i]] == 0 ? " " : "|");
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < len; i++) {//中
		cout << " ";
		for (int j = 0; j < k; j++) cout << (m[3][num[i]] == 0 ? " " : "-");
		cout << "  ";
	}
	cout << endl;
	for (int t = 0; t < k; t++) {//下左下右
		for (int i = 0; i < len; i++) {
			cout << (m[4][num[i]] == 0 ? " " : "|");
			for (int j = 0; j < k; j++) cout << " ";
			cout << (m[5][num[i]] == 0 ? " " : "|");
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < len; i++) {//下
		cout << " ";
		for (int j = 0; j < k; j++) cout << (m[6][num[i]] == 0 ? " " : "-");
		cout << "  ";
	}
	cout << endl;
	return 0;
}
