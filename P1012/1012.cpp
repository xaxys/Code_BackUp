#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int n, x, num[21];
string s[21], ans;
bool cmp(string& a, string& b) { return a + b > b + a; }
int main(int argc, char **argv) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) cout << s[i];
	return 0;
}