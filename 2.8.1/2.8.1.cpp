#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#define ll long long
#define maxx 5000000
using namespace std;
ll t, pr[maxx], tot = 1, ans[maxx], sum[maxx];
bool f[maxx];
int main() {
	scanf("%lld", &t);
	memset(f, 0, sizeof(f));
	memset(ans, 0, sizeof(0));
	ans[1] = 1;
	for (int i = 2; i < maxx; i++) {
		if (!f[i]) {
			pr[tot] = i;
			tot++;
			ans[i] = i + 1;
		}
		for (int j = 1; j < tot && i*pr[j] < maxx; j++) {
			f[i*pr[j]] = 1;
			ll t = i, r = pr[j] + 1;
			for (; t % pr[j] == 0; t /= pr[j]) r = r * pr[j] + 1;
			ans[i*pr[j]] = ans[t] * r;
			if (!(i%pr[j])) break;
		}
	}
	while (t--) {
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", ans[x] - x);
	}
	/*memset(sum,0,sizeof(sum));
	for (int i = 1; i <= maxx; i++) {
		for(int j = i*2 ;j < maxx; j += i){
			sum[j] += i;
		}
	}
	while (t--) {
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", sum[x]);
	}*/

}