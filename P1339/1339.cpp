#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

class side {
public:
	int from, to, value;
	side(int a, int b, int c) : from(a), to(b), value(c) {}
};
class que {
public:
	int p, d;
	que(int a, int b): p(a), d(b) {}
	bool operator < (const que& b) const {return d > b.d;}
};
int t, c, ts, te, d[5000], ans = 0;
bool done[5000];
vector<int> map[5000];
vector<side> sides;
priority_queue<que> q;

void readin() {
	for (int i = 1; i <= 5000; i++) d[i] = 2147483647;
	memset(done, 0, sizeof(done));
	cin >> t >> c >> ts >> te;
	for (int i = 0; i < c; i++) {
		int rs, re, v;
		cin>>rs>>re>>v;
		sides.push_back(side(rs, re, v));
		map[rs].push_back(sides.size() - 1);
		sides.push_back(side(re, rs, v));
		map[re].push_back(sides.size() - 1);
	}
}

int main() {
	readin();
	q.push(que(ts, 0));
	d[ts] = 0;
	while (!q.empty()) {
		que x = q.top();
		q.pop();
		if (x.p == te) break;
		if (done[x.p]) continue;
		done[x.p] = 1;
		for (int i = 0; i < map[x.p].size(); i++){
			side& s = sides[map[x.p][i]];
			if (d[s.to] > d[x.p] + s.value){
				d[s.to] = d[x.p] + s.value;
				q.push(que(s.to, d[s.to]));
			}
		}
	}
	cout<<d[te]<<endl;
	return 0;
}