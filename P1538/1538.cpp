#include<iostream>
#include<string>
using namespace std;
const int m[7][11] = {
	{ 1,0,1,1,0,1,1,1,1,1 },//��0
	{ 1,0,0,0,1,1,1,0,1,1 },//����1
	{ 1,1,1,1,1,0,0,1,1,1 },//����2
	{ 0,0,1,1,1,1,1,0,1,1 },//��3
	{ 1,0,1,0,0,0,1,0,1,0 },//����4
	{ 1,1,0,1,1,1,1,1,1,1 },//����5
	{ 1,0,1,1,0,1,1,0,1,1 }//��6
};
int k, num[256];
string s;
int main(int argc, char **argv) {
	cin >> k >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) num[i] = s[i] ^ 48;
	for (int i = 0; i < len; i++) {//��
		cout << " ";
		for (int j = 0; j < k; j++) cout << (m[0][num[i]] == 0 ? " " : "-");
		cout << "  ";
	}
	cout << endl;
	for (int t = 0; t < k; t++) {//��������
		for (int i = 0; i < len; i++) {
			cout << (m[1][num[i]] == 0 ? " " : "|");
			for (int j = 0; j < k; j++) cout << " ";
			cout << (m[2][num[i]] == 0 ? " " : "|");
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < len; i++) {//��
		cout << " ";
		for (int j = 0; j < k; j++) cout << (m[3][num[i]] == 0 ? " " : "-");
		cout << "  ";
	}
	cout << endl;
	for (int t = 0; t < k; t++) {//��������
		for (int i = 0; i < len; i++) {
			cout << (m[4][num[i]] == 0 ? " " : "|");
			for (int j = 0; j < k; j++) cout << " ";
			cout << (m[5][num[i]] == 0 ? " " : "|");
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < len; i++) {//��
		cout << " ";
		for (int j = 0; j < k; j++) cout << (m[6][num[i]] == 0 ? " " : "-");
		cout << "  ";
	}
	cout << endl;
	return 0;
}
