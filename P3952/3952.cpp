#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<set>
#define open(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin); fclose(stdout);
using namespace std;
int t;
set<string> rec;

int StringtoInt(string s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

int check(int &line, int n, string prevname) {
	if (line > n) return -1000;
	int f = 1, o = 0;
	while (f && line <= n) {
		string s, ch, name, sfrom, sto;
		int from = 100000, to = 100000, onow = 0;
		getline(cin, s);
		stringstream ss(s);
		ss >> ch;
		line++;
		if (ch == "F") {
			ss >> name >> sfrom >> sto;
			if (rec.count(name)) return -1000;
			rec.insert(name);
			if (sfrom != "n") from = StringtoInt(sfrom);
			if (sto != "n") to = StringtoInt(sto);
			if (from > to) {
				int tmp = check(line, n, name);
				if (tmp < 0) onow = -1000;
			}
			else if ((from < 110 && to < 110) || (from == 100000 && to == 100000)) onow = check(line, n, name);
			else onow = 1 + check(line, n, name);
			if (onow < 0) f = 0;
			o = max(o, onow);
		}
		else {
			if (!rec.empty()) {
				rec.erase(prevname);
				return o;
			}
			return -1000;
		}
	}
	if (!f) return -1000;
	return o;
}

void n_o(int& n, int& on, string s) {
	int x = 0, k = 0;
	while (s[k] <= '9'&&s[k] >= '0') x = (x << 3) + (x << 1) + (s[k] ^ 48), k++;
	n = x;
	if (s[k + 3] == n) on = 0;
	else {
		k += 5;
		x = 0;
		while (s[k] <= '9'&&s[k] >= '0') x = (x << 3) + (x << 1) + (s[k] ^ 48), k++;
		on = x;
	}
}

void program() {
	rec.clear();
	string inf;
	int n, o, realo, line = 1;
	getline(cin, inf);
	n_o(n, o, inf);
	rec.insert("main");
	realo = check(line, n, "main");
	if (realo < 0 || rec.size()!=1) {
		cout <<"ERR"<< endl;
		while (line <= n) line++,getline(cin, inf);
	}
	else if (realo == o) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	//open("complexity");
	string st;
	getline(cin, st);
	stringstream ss(st);
	ss >> t;
	while (t--) {
		program();
	}
	//close;
	return 0;
}