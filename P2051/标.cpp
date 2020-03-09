#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstring>
#define mod 9999973
#define int long long
#define R register
using namespace std;
inline void in(int &x)
{
  int f = 1;
  x = 0;
  char s = getchar();
  while (!isdigit(s))
  {
    if (s == '-')
      f = -1;
    s = getchar();
  }
  while (isdigit(s))
  {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
int n, m, ans;
int f[108][108][108];
inline int C(int x)
{
  return ((x * (x - 1)) / 2) % mod;
}
signed main()
{
  in(n), in(m);
  f[0][0][0] = 1;
  for (R int i = 1; i <= n; i++)
  {
    for (R int j = 0; j <= m; j++)
    {
      for (R int k = 0; k <= m - j; k++)
      {
        f[i][j][k] = f[i - 1][j][k];
        if (k >= 1)
          (f[i][j][k] += f[i - 1][j + 1][k - 1] * (j + 1));
        if (j >= 1)
          (f[i][j][k] += f[i - 1][j - 1][k] * (m - j - k + 1));
        if (k >= 2)
          (f[i][j][k] += f[i - 1][j + 2][k - 2] * (((j + 2) * (j + 1)) / 2));
        if (k >= 1)
          (f[i][j][k] += f[i - 1][j][k - 1] * j * (m - j - k + 1));
        if (j >= 2)
          (f[i][j][k] += f[i - 1][j - 2][k] * C(m - j - k + 2));
        f[i][j][k] %= mod;
      }
    }
  }
  for (R int i = 0; i <= m; i++)
    for (R int j = 0; j <= m; j++){
      (ans += f[n][i][j]) %= mod;
      printf("[%d][%d] %d\n", i, j, f[n][i][j]);
    }
  printf("%lld", (ans + mod) % mod);
}