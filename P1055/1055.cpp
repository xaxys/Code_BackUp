#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	//0-670-82162-4
	int x = ((s[0]^48) + ((s[2]^48) << 1) + (s[3]^48) * 3 + ((s[4]^48) << 2) + (s[6]^48) * 5 + (s[7]^48) * 6 + (s[8]^48) * 7 + ((s[9]^48) << 3) + (s[10]^48) * 9) % 11;
	if (x == (s[12] == 'X' ? 10 : (s[12]^48))) cout << "Right" << endl;
	else cout << s.substr(0, 12) << (x == 10 ? 'X' : char(x+48)) << endl;
	return 0;
}