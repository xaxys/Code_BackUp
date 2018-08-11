//八数码问题广搜版
/*#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include<string>
#define target "123804765"
using namespace std;
string source;
set<string> rec;
queue< pair<string,int> > q;
int ans = -0x7f7f7f7f;
void addque(queue< pair<string, int> > &q, set<string> &rec, string s, int t) {
	int pos = 0;
	while (s[pos] != '0') pos++;
	if (pos >= 3) {
		string s0 = s;
		swap(s0[pos], s0[pos - 3]);
		if (!rec.count(s0)) q.push(make_pair(s0, t)), rec.insert(s0);
	}
	if (pos <= 5) {
		string s0 = s;
		swap(s0[pos], s0[pos + 3]);
		if (!rec.count(s0)) q.push(make_pair(s0, t)), rec.insert(s0);
	}
	if (pos % 3 >= 1) {
		string s0 = s;
		swap(s0[pos], s0[pos - 1]);
		if (!rec.count(s0)) q.push(make_pair(s0, t)), rec.insert(s0);
	}
	if (pos % 3 <= 1) {
		string s0 = s;
		swap(s0[pos], s0[pos + 1]);
		if (!rec.count(s0)) q.push(make_pair(s0, t)), rec.insert(s0);
	}
}
int main() {
	cin >> source;
	rec.insert(source);
	q.push(make_pair(source,0));
	while (!q.empty()) {
		string s = q.front().first;
		int t = q.front().second;
		q.pop();
		if (s == target) {
			ans = t;
			break;
		}
		addque(q, rec, s, t + 1);
	}
	cout << ans << endl;
	return 0;
}*/
//双向广搜版
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<string>
#define target "123804765"
using namespace std;
string source;
map< string, pair<int, int> > rec;
queue<string> q1, q2;
int ans = 0;
bool addque(queue<string> &q, map< string, pair<int, int> > &rec, string s, int t, int num) {
	int pos = 0;
	while (s[pos] != '0') pos++;
	if (pos >= 3) {
		string s0 = s;
		swap(s0[pos], s0[pos - 3]);
		if (!rec.count(s0)) q.push(s0), rec[s0] = make_pair(t, num);
		else if (rec[s0].second == 1 - num) {
			ans = t + rec[s0].first;
			return 0;
		}
	}
	if (pos <= 5) {
		string s0 = s;
		swap(s0[pos], s0[pos + 3]);
		if (!rec.count(s0)) q.push(s0), rec[s0] = make_pair(t, num);
		else if (rec[s0].second == 1 - num) {
			ans = t + rec[s0].first;
			return 0;
		}
	}
	if (pos % 3 >= 1) {
		string s0 = s;
		swap(s0[pos], s0[pos - 1]);
		if (!rec.count(s0)) q.push(s0), rec[s0] = make_pair(t, num);
		else if (rec[s0].second == 1 - num) {
			ans = t + rec[s0].first;
			return 0;
		}
	}
	if (pos % 3 <= 1) {
		string s0 = s;
		swap(s0[pos], s0[pos + 1]);
		if (!rec.count(s0)) q.push(s0), rec[s0] = make_pair(t, num);
		else if (rec[s0].second == 1 - num) {
			ans = t + rec[s0].first;
			return 0;
		}
	}
	return 1;
}
int main() {
	cin >> source;
	rec[source] = make_pair(0, 0);
	rec[target] = make_pair(0, 1);
	q1.push(source);
	q2.push(target);
	if (source == target) { cout << 0 << endl; return 0; }
	while (!q1.empty() || !q2.empty()) {
		if (!q1.empty()) {
			string s1 = q1.front();
			int t1 = rec[s1].first;
			q1.pop();
			if (!addque(q1, rec, s1, t1 + 1, 0)) break;
		}
		if (!q2.empty()) {
			string s2 = q2.front();
			int t2 = rec[s2].first;
			q2.pop();
			if (!addque(q2, rec, s2, t2 + 1, 1)) break;
		}
	}
	cout << ans << endl;
	return 0;
}
