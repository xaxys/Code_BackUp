#include <iostream>
#include <string>
using namespace std;
string read;
int n, length=1;
void build(string st,int depth) {
	if (!depth) {
		switch (st[0]) {
		case '0':cout << "B"; break;
		case '1':cout << "I"; break;
		}
		return;
	}
	int len = st.size() / 2;
	build(st.substr(0, len), depth - 1);
	build(st.substr(len, len), depth - 1);
	char tp;
	bool f = 1;
	tp = st[0];
	for (int i = 1; i < len * 2; i++) {
		if (st[i] != tp) {
			f = 0;
			break;
		}
	}
	if (f == 0) cout<<"F";
	else if (tp=='1') cout<<"I";
	else cout<<"B";
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) length *= 2;
	cin >> read;
	build(read,n);
	cout << endl;
	return 0;
}