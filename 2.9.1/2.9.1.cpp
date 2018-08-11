#include<iostream> 
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>
#define ll long long
#define maxn 1000010
using namespace std;
bool f[maxn];
int main() {
	ll l, r;
	while (scanf("%lld%lld", &l, &r) == 2) {
		memset(f, 0, sizeof(f));
		const ll root = (int)sqrt(r) + 1;
		ll t, pr[maxn], tot = 1, print = 0;
		for (int i = 2; i < root; i++) {
			if (!f[i]) {
				pr[tot] = i;
				tot++;
			}
			for (int j = 1; j < tot && i*pr[j] < root; j++) {
				f[i*pr[j]] = 1;
				if (!(i%pr[j])) break;
			}
		}
		memset(f, 0, sizeof(f));
		for (ll i = 1; i < tot; i++) {
			ll k = ceil(l / pr[i]);
			if (k*pr[i] < l) k++;
			for (int j = pr[i] * k; j <= r; j += pr[i]) 
				if(j != pr[i]) f[j - l] = 1;
		}
		for (ll i = l; i <= r; i++) {
			if (!f[i - l]) print += i;
		}
		if (l == 1)print--;
		printf("%lld\n", print);
	}
}