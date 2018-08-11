#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cctype>
using namespace std;
class st_table {
	int d[100010][20];
public:
	void init(const vector<int>& a) {
		int n = a.size();
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++) d[i][0] = a[i];
		for (int j = 1; (1<<j) <= n; j++)
			for (int i = 0; i + (1 << j) - 1 < n; i++) {
				d[i][j] = max(d[i][j - 1], d[i + (1 << (j-1))][j - 1]);
			}
	}
	int rmq(int l, int r) {
		int k = 0;
		while ((1 << (k + 1)) <= r-l+1) k++;
		return max(d[l][k], d[r - (1 << k) + 1][k]);
	}
};

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	for (; ch<'0' || ch>'9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0'&&ch <= '9'; x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar());
	return x*f;
}
vector<int> a;
int n, m;
st_table st;

int main() {
	n = read();
	m = read();
	while (n--) {
		int x = read();
		a.push_back(x);
	}
	st.init(a);
	while (m--) {
		int l=read(),r=read();
		printf("%d\n", st.rmq(l - 1, r - 1));
	}
	return 0;
}