#include<bits/stdc++.h>
using namespace std;
map<string, string> m = {
	{"zero"		, "00"},
	{"one"		, "01"},
	{"two"		, "04"},
	{"three"	, "09"},
	{"four"		, "16"},
	{"five"		, "25"},
	{"six"		, "36"},
	{"seven"	, "49"},
	{"eight"	, "64"},
	{"nine"		, "81"},
	{"ten"		, "00"},
	{"eleven"	, "21"},
	{"twelve"	, "44"},
	{"thirteen"	, "69"},
	{"fourteen"	, "96"},
	{"fifteen"	, "25"},
	{"sixteen"	, "56"},
	{"seventeen", "89"},
	{"eighteen"	, "24"},
	{"nineteen"	, "61"},
	{"twenty"	, "00"},
	{"a"		, "01"},
	{"both"		, "04"},
	{"another"	, "09"},
	{"first"	, "01"},
	{"second"	, "04"},
	{"third"	, "09"}
};
int main() {
	string s;
	vector<string> vec;
	while (cin >> s) if (m.count(s)) vec.push_back(m[s]);
	if (vec.size() == 0) {
		cout << 0;
		return 0;
	}
	sort(vec.begin(), vec.end());
	auto it = vec.begin();
	while (*it == "00") it++;
	if ((*it)[0] != '0') cout << (*it)[0]; cout << (*it)[1], it++;
	for (; it != vec.end(); it++) cout << *it;
	return 0;
}