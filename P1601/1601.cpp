#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cctype>
#define N 1000000 + 10
#define BASE 1000
#define WIDTH 3
using namespace std;

class BigInteger {
	int num[N], size = 1;
private:
	int getInt(string &s, int a, int duoyu) {
		int x = 0, lim = max(duoyu, a - WIDTH + 1);
		for (int i = lim; i <= a; i++) x = x * 10 + s[i] - '0';
		return x;
	}
public:
	BigInteger() {
		memset(num, 0, sizeof(num));
		size = 1;
	}
	friend ostream &operator << (ostream &out, BigInteger &b) {
		out << b.num[b.size];
		for (int i = b.size - 1; i > 0; i--) out << setw(WIDTH) << setfill('0') << b.num[i];
		return out;
	}
	friend istream &operator >> (istream &in, BigInteger &b) {
		string s;
		in >> s;
		b = s;
		return in;
	}
	BigInteger &operator = (string &s) {
		memset(num, 0, sizeof(num));
		int len = s.length(), duoyu = 0;
		while (s[duoyu] == '0') duoyu++;
		for (int i = len - 1; i >= duoyu; i -= WIDTH, size++) num[size] = getInt(s, i, duoyu);
		size--;
		return *this;
	}
	BigInteger &operator = (BigInteger &b) {
		memset(this->num, 0, sizeof(this->num));
		memcpy(this->num, b.num, sizeof(b.num));
		this->size = b.size;
		return *this;
	}
	BigInteger &operator + (BigInteger &b) {
		this->size = max(this->size, b.size);
		for (int i = 1; i <= this->size; i++) {
			if(i <= b.size) this->num[i] += b.num[i];
			this->num[i + 1] += this->num[i] / BASE;
			this->num[i] %= BASE;
		}
		if (this->num[size + 1] > 0) size++;
		return *this;
	}
	BigInteger &operator * (BigInteger &b) {
		BigInteger c;
		c.size = this->size * b.size;
		for (int i = 1; i <= this->size; i++) {
			for (int j = 1; j <= b.size; j++) {
				c.num[i + j - 1] += this->num[i] * b.num[j];
			}
		}
		for (int i = 1; i <= c.size; i++) {
			c.num[i + 1] += c.num[i] / BASE;
			c.num[i] %= BASE;
		}
		while (c.num[c.size] == 0 && c.size > 1) c.size--;
		*this = c;
		return *this;
	}
};
int main() {
	BigInteger a, b;
	cin >> a >> b;
	cout << a * b << endl;
	return 0;
}