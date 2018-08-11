#include<bits/stdc++.h>
using namespace std;
int n;
inline char move(char ch) {
	return char((((ch - 'a') + n) % 26) + 'a');
}
int main() {
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.length(); i++) cout << move(s[i]);
	return 0;
}