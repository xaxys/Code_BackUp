#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 200;
struct BIG
{
	int len, s[maxn];
	BIG()
	{
		memset(s, 0, sizeof(s));
		len = 1;
	}
	BIG(int num)
	{
		*this = num;
	}
	// 定义为const参数，作用是 不能对const参数的值做修改
	BIG(const char* num)
	{
		*this = num;
	}
	// 以上是构造方法，初始化时对执行相应的方法
	BIG operator = (int num)
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	// 函数定义后的const关键字，它表明"x.str()不会改变x"
	string str() const
	{
		string res = "";
		for (int i = 0; i < len; i++)
			res = (char)(s[i] + '0') + res;
		if (res == "") res = "0";
		return res;
	}
	void clean()
	{
		while (len > 1 && !s[len - 1])
			len--;
	}
	// 重载操作符
	BIG operator = (const char* num)
	{
		// 逆序存储
		len = strlen(num);
		for (int i = 0; i < len; i++)
			s[i] = num[len - i - 1] - '0';
		return *this;
	}
	BIG operator + (const BIG& b) const
	{
		BIG c;
		c.len = 0;
		for (int i = 0, g = 0; g || i < max(len, b.len); i++)
		{
			int x = g;
			if (i < len) x += s[i];
			if (i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}
	BIG operator * (const BIG& b)
	{
		BIG c; c.len = len + b.len;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < b.len; j++)
				c.s[i + j] += s[i] * b.s[j];
		for (int i = 0; i < c.len - 1; i++)
		{
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}
	BIG operator - (const BIG& b) {
		BIG c; c.len = 0;
		for (int i = 0, g = 0; i < len; i++)
		{
			int x = s[i] - g;
			if (i < b.len)
				x -= b.s[i];
			if (x >= 0)
				g = 0;
			else
			{
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}
	bool operator < (const BIG& b) const
	{
		if (len != b.len)
			return len < b.len;
		for (int i = len - 1; i >= 0; i--)
			if (s[i] != b.s[i])
				return s[i] < b.s[i];
		return false;
	}
	bool operator > (const BIG& b) const
	{
		return b < *this;
	}
	bool operator <= (const BIG& b)
	{
		return !(b > *this);
	}
	bool operator == (const BIG& b)
	{
		return !(b < *this) && !(*this < b);
	}
	BIG operator += (const BIG& b)
	{
		*this = *this + b;
		return *this;
	}
	friend istream& operator >> (istream &in, BIG& x)
	{
		string s;
		in >> s;
		x = s.c_str();
		return in;
	}
	friend ostream& operator << (ostream &out, const BIG& x)
	{
		out << x.str();
		return out;
	}
};

int main()
{
	int n;
	BIG f[205];
	f[1] = 2;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		f[i] = (f[i - 1] + 1) * 2;
	}
	cout << f[n] << endl;
	return 0;
}