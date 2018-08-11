#include<cstdio>
#include<cctype>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n, g[2000010], rec[2000010], nextf = 1, minn=0x7f7f7f7f;
int next() {
	for (int i = nextf; i <= n; i++) {
		if (!rec[i]) {
			nextf = i + 1;
			return i;
		}
	}
	return 0;
}
int main() {
	int t = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &g[i]);
	memset(rec, 0, sizeof(rec));
	int s = next();
	while (s) {
		int st = t;
		int np = s;
		while (!rec[np]) {
			rec[np] = t;
			t++;
			np = g[np];
		}
		if (rec[np] >= st) minn = min(minn, t - rec[np]);
		s = next();
	}
	printf("%d\n",minn);
}