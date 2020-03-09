#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    ll ans = 0;
    ll x, last = -(1 << 62);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x);
        if (x > last) ans += x - last;
        last = x;
    }
    printf("%lld", ans);
    return 0;
}