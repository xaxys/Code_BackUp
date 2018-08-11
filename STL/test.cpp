#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
using namespace std;
int main() {
	vector<int> a;
	vector<int> b(10, 2048);
	deque<int> c;
	list<int> d;
	map <int, int> e;
	map <int, int>::iterator it;
	for (int i = 1; i < 5; i++) {
		int j;
		cin >> j;
		b.push_back(j);
		c.push_back(j + 10);
		e.insert(pair<int, int>(i, j));
	}
	for (int i = 10; i < 14; i++) {

		a.push_back(b[i]);
		c.push_front(b[i]);
	}
	cout << a.size() << endl;
	cout << a.back() << endl;
	a.pop_back();
	for (it = e.begin(); it != e.end(); it++) cout << it->first << " " << it->second << endl;
	it = e.find(4);
	if (it != e.end()) cout << it->second << endl;
}