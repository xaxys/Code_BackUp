#include <bits/stdc++.h>
using namespace std;
int ans;
int tmp;
string s;
int main() {
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			tmp++;
			if (ans < tmp) ans = tmp;
		}
		else tmp--;
		if (tmp < 0) tmp = 0;
	}
	printf("%d\n", ans ? ans : -1);
	return 0;
}
