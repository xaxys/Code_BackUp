#include<cstdio>
#include<cstring>
#include<climits>
#define max(a, b) (a > b ? a : b)
#define ini int lc = o << 1, rc = o << 1 | 1, m = l + r >> 1;
#define pushup(x) maxv[x] = max(maxv[lc], maxv[rc]);
#define N 200010
int m, d;
class SegmentTree {
	int t, maxv[N << 1], tail;
	int v, qL, qR, ans;
	inline void update(int l, int r, int o) {
		if (l == r) {
			maxv[o] = v;
			return;
		}
		ini;
		if (qL <= m) update(l, m, lc);
		else update(m + 1, r, rc);
		pushup(o);
	}
	inline void query(int l, int r, int o) {
		if (qL <= l && r <= qR) {
			ans = max(ans, maxv[o]);
			return;
		}
		ini;
		if (qL <= m) query(l, m, lc);
		if (qR > m) query(m + 1, r, rc);
	}
public:
	inline void init() {
		tail = t = 0;
		memset(maxv, -0x7f, sizeof(maxv));
	}
	inline void A(int n) {
		t = v = (n + t) % d;
		qL = ++tail;
		update(1, m, 1);
	}
	inline int Q(int n) {
		if (n == 0) return 0;
		ans = INT_MIN;
		qL = tail - n + 1;
		qR = tail;
		query(1, m, 1);
		return ans;
	}
} sgt;
int main() {
	scanf("%d%d", &m, &d);
	sgt.init();
	for (int i = 1; i <= m; i++) {
		char ch;
		int k;
		scanf("%*[\n]%c %d", &ch, &k);
		if (ch == 'A') sgt.A(k);
		else printf("%d\n", sgt.Q(k));
	}
	return 0;
}