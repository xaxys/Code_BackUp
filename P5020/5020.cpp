#include<bits/stdc++.h>
#define clear(x) memset(x, 0, sizeof(x));
using namespace std;
const int N = 110;
const int A = 25010;
int t;
int main() {
    scanf("%d", &t);
    while (t--) {
        int n, a[N], ans = 0;
        int f[A]; clear(f);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            f[a[i]] = -1;
        }
        sort(a + 1, a + n + 1);
        for (int i = a[1]; i < a[n]; i++) {
            if (f[i]) {
                for (int j = 1; (i + a[j]) <= a[n]; j++) {
                    f[i + a[j]] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            ans += !~f[a[i]];
        }
        printf("%d\n", ans);
    }
}