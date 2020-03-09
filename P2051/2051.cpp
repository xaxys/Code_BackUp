#include<bits/stdc++.h>
#define C(x) ((((x) * ((x) - 1)) / 2) % MOD)
const int MOD = 9999973;
typedef long long ll;
using namespace std;
int n, m;
ll f[2][110][110];
int main() {
    f[0][0][0] = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int a = i & 1;
        int b = a ^ 1;
        memset(f[a], 0, sizeof(f[a]));
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m - j; k++) {
                f[a][j][k] = f[b][j][k];
                if (k >= 1)
                    f[a][j][k] += f[b][j + 1][k - 1] * (j + 1);
                if (j >= 1)
                    f[a][j][k] += f[b][j - 1][k] * (m - j - k + 1);
                if (k >= 2)
                    f[a][j][k] += f[b][j + 2][k - 2] * C(j + 2);
                if (k >= 1)
                    f[a][j][k] += f[b][j][k - 1] * j * (m - j - k + 1);
                if (j >= 2)
                    f[a][j][k] += f[b][j - 2][k] * C(m - j - k + 2);
                f[a][j][k] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            ans += f[n & 1][i][j];
            ans %= MOD;
        }
    }
    printf("%lld\n", ans);
}