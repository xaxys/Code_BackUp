#include<bits/stdc++.h>
#define N 500010
#define clr(a) memset(a, 0, sizeof(a))
using namespace std;
class SBT {
	int ans;
	int root, cnt;
	int data[N], ch[N][2], sz[N];
	void rotate(int &x, int d) {
		int tmp = ch[x][d];
		ch[x][d] = ch[tmp][d ^ 1];
		ch[tmp][d ^ 1] = x;
		sz[tmp] = sz[x];
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
		x = tmp;
	}
	void maintain(int &x) {
		for (int i = 0; i < 2; i++) {
			if (sz[ch[ch[x][i]][i]] > sz[ch[x][i ^ 1]]) {
				rotate(x, i);
				maintain(ch[x][i ^ 1]);
				maintain(x);
				break;
			}
			if (sz[ch[ch[x][i]][i ^ 1]] > sz[ch[x][i ^ 1]]) {
				rotate(ch[x][i], i ^ 1);
				rotate(x, i);
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
			insert(ch[x][data[x] < k], k);
			maintain(x);
		}
	}
	int erase(int &x, int k) {
		if (!x) return 0;
		if (data[x] < k) {
			tot_del += sz[ch[x][0]] + 1;
			return x = erase(ch[x][1], k);
		}
		else {
			erase(ch[x][0], k);
			sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
			return x;
		}
	}
	void select(const int x, int k) {
		if (!x) return;
		if (k <= sz[ch[x][1]]) select(ch[x][1], k);
		else if (k == sz[ch[x][1]] + 1) ans = data[x];
		else select(ch[x][0], k - sz[ch[x][1]] - 1);
	}
public:
	int add, mingz, tot_del;
	SBT() {
		root = cnt = tot_del = 0;
		clr(data); clr(ch); clr(sz);
	}
	void insert(int k) {
		if (k < mingz) return;
		insert(root, k - add);
	}
	void erase() { erase(root, mingz - add); }
	int select(int k) {
		if (k > sz[root]) return -1;
		select(root, k);
		return ans + add;
	}
	void A(int k) { add += k; }
	void S(int k) { add -= k; }
} sbt;
int n, k;
char ch;
int main() {
	cin >> n >> sbt.mingz;
	while (n--) {
		cin >> ch >> k;
		if (ch == 'I') sbt.insert(k);
		else if (ch == 'A') sbt.A(k);
		else if (ch == 'S') sbt.S(k), sbt.erase();
		else if (ch == 'F') cout << sbt.select(k) << endl;
	}
	cout << sbt.tot_del << endl;
	return 0;
}
