#include<cstdio>
#include<algorithm>
#define N 3000
using namespace std;
int c, l, ans;
struct cow {
	int min, max;
	bool operator < (const cow &b) const {
		if (max == b.max) return min > b.min;
		return max < b.max;
	}
} niu[N];
struct sunscreen {
	int spf, num;
	sunscreen(int a = 0, int b = 0) : spf(a), num(b) {}
	bool operator < (const sunscreen &b) const {
		return spf < b.spf;
	}
} fss[N];
int main() {
	scanf("%d%d", &c, &l);
	for (int i = 0; i < c; i++) scanf("%d%d", &niu[i].min, &niu[i].max);
	for (int i = 0; i < l; i++) scanf("%d%d", &fss[i].spf, &fss[i].num);
	sort(niu, niu + c);
	sort(fss, fss + l);
	for (int i = 0; i < c; i++) {
		int pos = lower_bound(fss, fss + l, sunscreen(niu[i].min, 0)) - fss;
		if (pos == l) continue;
		for (int j = pos; fss[j].spf <= niu[i].max; j++) {
			if (fss[j].num) {
				fss[j].num--;
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}