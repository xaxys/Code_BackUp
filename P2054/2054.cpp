#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ul;
inline int log2(ll x) {
    float fx = (float)x;
    ul ix = *(ul*)&fx;
    return ((ix >> 23) & 0xFF) - 127;
}
int main() {
    ll n, m, l;
    scanf("%lld%lld%lld", &n, &m, &l);

    int x = log2((l & (-l)));
    while (m > x) {
        l >>= x;
        l = (l + n + 1) >> 1;
        m -= x + 1;
        x = log2((l & (-l)));
    }

    printf("%lld\n", l >> m);
    return 0;
}

