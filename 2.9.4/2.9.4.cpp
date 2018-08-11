#include<iostream> 
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cmath>
#include<vector>
#include<map>
#define ll long long
#define maxn 1000010
using namespace std;
int toInt(char ch) {
	if (isdigit(ch)) return ch ^ 48;
	if (isupper(ch)) return ch - 'A' + 10;
	return ch - 'a' + 36;
}
int pr[] = { 2, 3, 5, 7 }, ans = 0;
int main() {
	ios::sync_with_stdio(false);
	string s;
	ll n = 0, base;
	while (cin >> s >> base) {
		ans = n = 0;
		for (int i = 0; i < s.length(); i++) {
			n = n * base + toInt(s[i]);
		}
		int tab[4] = { 1, 1, 1, 1 };
		for (int i = 0; i < 4 && base > 1; i++) {
			while (!(base % pr[i])) {
				base /= pr[i];
				tab[i] *= pr[i];
			}
		}
		int k = tab[0];
		for (int i = 1; i < 4; i++) k = max(k, tab[i]);
		for (int i = k; i <= n; i++) {
			int j = i;
			while (!(j % k)) {
				j /= k;
				ans++;
			}
		}
		cout << ans << endl;
	}
}