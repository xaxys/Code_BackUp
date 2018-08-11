#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
class pos {
public:
	int depth, n;
};
int n, a, b, k[201];
bool rec[201];
queue<pos> que;
void bfs() {
	while (!que.empty()) {
		pos tmp = que.front();
		if (tmp.n == b) {
			cout << tmp.depth << endl;
			exit(0);
		}
		tmp.depth += 1;
		tmp.n = que.front().n + k[que.front().n];
		if (tmp.n <= n && !rec[tmp.n]) {
			que.push(tmp);
		}
		tmp.n = que.front().n - k[que.front().n];
		if (tmp.n >= 1 && !rec[tmp.n]) {
			que.push(tmp);
		}
		rec[que.front().n] = 1;
		que.pop();
	}
}
int main() {
	int i;
	memset(rec, 0, sizeof(rec));
	cin >> n >> a >> b;
	for (i = 1; i <= n; i++) cin >> k[i];
	pos tmp;
	tmp.n = a;
	tmp.depth = 0;
	que.push(tmp);
	bfs();
	cout << "-1" << endl;
	return 0;
}