#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
inline string quling(string s) {
	ll x;
	string s1;
	stringstream ss(s);
	stringstream ss1;
	ss >> x;
	ss1 << x;
	return ss1.str();
}
inline ll reverse(string s1) {
	string s = quling(s1);
	ll len = s.length();
	for (ll i = 0; i < len / 2; i++) swap(s[i], s[len - i - 1]);
	stringstream ss(s);
	ll x;
	ss >> x;
	return x;
}
int main() {
	string s;
	cin >> s;
	int p = s.find('.');
	int f = s.find('/');
	int baifen = s.find('%');
	if (p != -1) {
		cout << reverse(s.substr(0, p)) << "." << reverse(s.substr(p + 1)) << endl;
	}
	else if (f != -1) {
		cout << reverse(s.substr(0, f)) << "/" << reverse(s.substr(f + 1)) << endl;
	}
	else if (baifen != -1) {
		cout << reverse(s.substr(0, s.length() - 1)) << "%" << endl;
	}
	else {
		cout << reverse(s) << endl;
	}
	return 0;
}