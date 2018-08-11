#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<char> vec;
	char ch;
	cin >> ch;
	while (ch != '@') {
		if (ch == '[' || ch == '{' || ch == '(' ) {
			vec.push_back(ch);
		}
		else if (ch == ']' || ch == '}' || ch == ')') {
			char tmp;
			switch (ch) {
			case ']': tmp = '['; break;
			case '}': tmp = '{'; break;
			case ')': tmp = '('; break;
			}
			if (tmp == vec.back()) {
				vec.pop_back();
			}
			else {
				cout << "NO" << endl;
				exit(0);
			}
		}
		cin >> ch;
	}
	if (vec.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}