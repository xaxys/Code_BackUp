#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
int a[100010], n = 0;
void question1() {
	int g[100010], maxn = 0;
	memset(g, 0x3f, sizeof(g));
	for (int i = 0; i < n; i++) {
		int k = upper_bound(g + 1, g + n + 1, -a[i]) - g;
		maxn = max(maxn, k);
		g[k] = -a[i];
	}
	cout << maxn << endl;
}
void question2() {
	set<int> rec;
	/*set<int>::iterator it*/
	rec.insert(a[0]);
	for (int i = 1; i < n; i++) {
		auto it = rec.lower_bound(a[i]);
		if (it != rec.end()) rec.erase(it);
		rec.insert(a[i]);
	}
	cout << rec.size() << endl;
}
int main() {
	while (cin >> a[n++]);
	//for (int i = 0; i < 10; i++) cin >> a[i]; n = 10;
	question1();
	question2();
	return 0;
}