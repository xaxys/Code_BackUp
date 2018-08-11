#include<bits/stdc++.h>
using namespace std;

class Trie {
	struct node {
		short finish = 0;
		bool checked = 0;
		node* c[26];
	};
	node* root = new node();
public:
	void insert(string s) {
		node* ptr = root;
		for (int i = 0; i < s.length(); i++) {
			if (ptr->c[s[i] - 'a'] == nullptr)
				ptr->c[s[i] - 'a'] = new node();
			ptr = ptr->c[s[i] - 'a'];
		}
		ptr->finish++;
	}
	string check(string s) {
		node* ptr = root;
		for (int i = 0; i < s.length(); i++) {
			if (ptr->c[s[i] - 'a'] == nullptr) return "WRONG";
			ptr = ptr->c[s[i] - 'a'];
		}
		if (!ptr->finish) return "WRONG";
		if (ptr->checked) return "REPEAT";
		ptr->checked = 1;
		return "OK";
	}
};
int n, m;
string s;
Trie t;
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	while (n--) {
		cin >> s;
		t.insert(s);
	}
	cin >> m;
	while (m--) {
		cin >> s;
		cout << t.check(s) << endl;
	}
}