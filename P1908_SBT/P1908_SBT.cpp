#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#define N 50010
using namespace std;
class SBT {
	int root, cnt;
	int data[N], sz[N], ch[N][2];
	inline void rotate(int &x, int dir) {
		int t = ch[x][dir ^ 1];
		ch[x][dir ^ 1] = ch[t][dir];
		ch[t][dir] = x;
		sz[t] = sz[x];
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
		x = t;
	}
	inline void maintain(int &x) {
		for (int i = 0; i < 2; i++) {
			if (sz[ch[ch[x][i]][i]] > sz[ch[x][i ^ 1]]) {
				rotate(x, i ^ 1);
				maintain(ch[x][i ^ 1]);
				maintain(x);
				break;
			}
			if (sz[ch[ch[x][i]][i ^ 1]] > sz[ch[x][i ^ 1]]) {
				rotate(ch[x][i], i);
				rotate(x, i ^ 1);
				maintain(ch[x][0]);
				maintain(ch[x][1]);
				maintain(x);
				break;
			}
		}
	}
	void insert(int &x, int k) {
		if (!x) {
			data[++cnt] = k;
			sz[cnt] = 1;
			x = cnt;
		}
		else {
			sz[x]++;
			insert(ch[x][data[x] >= k], k);
			maintain(x);
		}
	}
	int order_of_key(int x, int k) {
		if (!x) return 0;
		if (data[x] <= k) return order_of_key(ch[x][0], k);
		else return sz[ch[x][0]] + order_of_key(ch[x][1], k) + 1;
	}
public:
	SBT() {
		root = cnt = 0;
		memset(data, 0, sizeof(data));
		memset(sz, 0, sizeof(sz));
		memset(ch, 0, sizeof(ch));
	}
	inline void insert(int k) { insert(root, k); }
	inline int order_of_key(int k) { return order_of_key(root, k); }
};
SBT sbt;
int n, ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		ans += sbt.order_of_key(x);
		sbt.insert(x);
	}
	printf("%d\n", ans);
	return 0;
}