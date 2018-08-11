#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class bign {
public:	
	const int width = 4, base = 10000;
	vector<int> s;
	bign (long long num = 0) { *this = num; }
	bign operator = (long long num) {
		s.clear();
		while (num > 0) {
			s.push_back(num % base);
			num /= base;
		}
		return *this;
	}
	bign operator = (string& str) {
		s.clear();
		int x, len = (str.length() - 1) / width + 1;
		for (int i = 0; i < len; i++) {
			int end = str.length() - i*width;
			int start = (end - width) > 0 ? end - width : 0;
			sscanf(str.substr(start, end - start).c_str(), "%d", &x);
			s.push_back(x);
		}
		return *this;
	}
	friend istream& operator >> (istream &in, bign& x) {
		string s;
		if (!(in >> s)) return in;
		x = s;
		return in;
	}
	bign operator + (bign& b) {
		bign c;
		c.s.clear();
		for (int i = 0, g = 0; g != 0 || i < s.size() || i < b.s.size(); i++) {
			int x = g;
			if (i < s.size()) x += s[i];
			if (i < b.s.size()) x += b.s[i];
			c.s.push_back(x%base);
			g = x / base;
		}
		return c;
	}
	bign operator - (bign& b) {
		bign c;
		int i,g;
		c.s.clear();
		for (i = 0,g = 0;i < b.s.size();i++) {
			s[i] -= g;
			g = 0;
			if (s[i] < b.s[i]) {
				g = 1;
				s[i] += base;
			}
			c.s[i] = s[i] - b.s[i];
		}
		while (i < s.size()) {
			c.s[i] = s[i] - g;
			g = 0;
		}
		return c;
	}
	bign operator * (bign& b) {
		bign c;
		int i,g=0;
		c.s.clear();
		for (i = 0; i < b.s.size(); i++) {
			int j;
			for (j = 0; j < s.size(); j++) {
				g = b.s[i] * s[j];
				c.s[i + j] += g / base;
				g %= base;
			}
			while (g > 0) {
				c.s[i + j] = g / base;
				g %= base;
			}
		}
		return c;
	}
	bign operator / (bign& b) {
		bign c;
		int i, g = 0;
		c.s.clear();

	}

};
bign n, k;
int main() {
	cin >> n >> k;
}