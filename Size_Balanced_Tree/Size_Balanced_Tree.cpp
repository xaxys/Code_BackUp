#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<algorithm>
using namespace std;

template<class T>
class SBT {
	class node {
	public:
		node* ch[2];
		int size = 1;
		int num = 1;
		int tot_size = 1;
		T data;
		node(T data) {
			this->ch[0] = this->ch[1] = nullptr;
			this->data = data;
		}
	};

	node* root = nullptr;
	T* ans;
	bool tag;
	int tmp;

	inline void update(node* x) {
		x->size = size(x->ch[0]) + size(x->ch[1]) + 1;
		x->tot_size = tot_size(x->ch[0]) + tot_size(x->ch[1]) + x->num;
	}
	inline int size(const node* x) const { return x == nullptr ? 0 : x->size; }
	inline int tot_size(const node* x) const { return x == nullptr ? 0 : x->tot_size; }
	inline void rotate(node* &x, int dir) {
		node* tmp = x->ch[dir ^ 1];
		x->ch[dir ^ 1] = tmp->ch[dir];
		tmp->ch[dir] = x;

		tmp->size = x->size;
		tmp->tot_size = x->tot_size;
		update(x);
		x = tmp;
	}
	inline void maintain(node* &x) {
		for (int i = 0; i < 2; i++) {
			if (x->ch[i] == nullptr) continue;
			if (size(x->ch[i]->ch[i]) > size(x->ch[i ^ 1])) {
				rotate(x, i ^ 1);
				maintain(x->ch[i ^ 1]);
				maintain(x);
				break;
			}
			if (size(x->ch[i]->ch[i ^ 1]) > size(x->ch[i ^ 1])) {
				rotate(x->ch[i], i);
				rotate(x, i ^ 1);
				maintain(x->ch[0]);
				maintain(x->ch[1]);
				maintain(x);
				break;
			}
		}
	}
	void insert(node* &x, T &k) {
		if (x == nullptr) {
			x = new node(k);
			tag = true;
		}
		else {
			x->tot_size++;
			if (x->data == k) {
				x->num++;
				tag = false;
				return;
			}
			insert(x->ch[x->data < k], k);
			if (tag) x->size++;
			maintain(x);
		}
	}
	void erase(node* &x, T &k) {
		if (x->data != k) {
			erase(x->ch[x->data < k], k);
			update(x);
		}
		else {
			if (x->num > 1) { x->num--; x->tot_size--; return; }
			node* p = x;
			if (x->ch[0] == nullptr) x = x->ch[1], delete p;
			else if (x->ch[1] == nullptr) x = x->ch[0], delete p;
			else {
				for (p = x->ch[1]; p->ch[0] != nullptr; p = p->ch[0]);
				x->num = p->num;
				x->data = p->data;
				p->num = 1;
				erase(x->ch[1], p->data);
				update(x);
			}
		}
	}
	int rank(const node* x, T &k) const {
		if (x == nullptr) return 0;
		if (x->data == k) return rank(x->ch[0], k) + 1;
		if (x->data > k) return rank(x->ch[0], k);
		return tot_size(x->ch[0]) + rank(x->ch[1], k) + x->num;
	}
	void select(node* x, int k) {
		if (x == nullptr) return;
		if (k <= tot_size(x->ch[0])) { select(x->ch[0], k); return; }
		if (k <= x->num + tot_size(x->ch[0])) { ans = &x->data; return; }
		select(x->ch[1], k - tot_size(x->ch[0]) - x->num);
	}
	void pred(node* x, const T &k) {
		if (x == nullptr)return;
		if (k > x->data) ans = &x->data, pred(x->ch[1], k);
		else pred(x->ch[0], k);
	}
	void succ(node* x, const T &k) {
		if (x == nullptr)return;
		if (k < x->data) ans = &x->data, succ(x->ch[0], k);
		else succ(x->ch[1], k);
	}
	string print(const node* x) {
		if (x == nullptr) return "";
		string s = print(x->ch[0]);
		s += tmp == root->size ? "" : " ";
		s += toString(x->data);
		if (x->num > 1) s += " x" + toString(x->num);
		s += --tmp ? "," : "";
		s += print(x->ch[1]);
		return s;
	}
	string toString(T x) {
		stringstream ss;
		ss << x;
		return ss.str();
	}
public:
	inline void insert(T k) { insert(root, k); }
	inline void erase(T &k) { erase(root, k); }
	inline int rank(T k) { return rank(root, k); }
	inline T& select(int k) { select(root, k); return *ans; }
	inline T& pred(T k) { pred(root, k); return *ans; }
	inline T& succ(T k) { succ(root, k); return *ans; }
	inline int size() { return root->tot_size; }
	inline bool empty() { return root == nullptr; }
	inline string print() { tmp = root->size; return "Data: [" + print(root) + "]" + char(10); }
	T& operator[] (int k) { return select(k + 1); }
};
int main() {
	SBT<int> sbt;
	string s;
	for (cin >> s; s != "exit"; cin >> s) {
		int arg;
		if (s == "insert" || s == "i") {
			cin >> arg;
			sbt.insert(arg);
			cout << "Insert Complete!" << endl;
		}
		else if (s == "erase" || s == "delete" || s == "e" || s == "d") {
			cin >> arg;
			sbt.erase(arg);
			cout << "Erase Complete!" << endl;
		}
		else if (s == "rank" || s == "r") {
			cin >> arg;
			cout << "Rank of " << arg << " is " << sbt.rank(arg) << endl;
		}
		else if (s == "select" || s == "s") {
			cin >> arg;
			cout << "The " << arg << "th number is " << sbt.select(arg) << endl;
		}
		else if (s[0] == '[' && s[s.size() - 1] == ']') {
			int arg = 0;
			for (int i = 1; i <= s.size() - 2; i++) if (isdigit(s[i])) arg = arg * 10 + s[i] - '0';
			cout << "SBT[" << arg << "] is " << sbt[arg] << endl;
		}
		else if (s == "pred") {
			cin >> arg;
			cout << "The predecessor of " << arg << " is " << sbt.pred(arg) << endl;
		}
		else if (s == "succ") {
			cin >> arg;
			cout << "The successor of " << arg << " is " << sbt.succ(arg) << endl;
		}
		else if (s == "print" || s == "p") {
			cout << sbt.print() << endl;
		}
		else if (s == "size" || s == "sz") {
			cout << "The size of SBT is " << sbt.size() << endl;
		}
		else if (s == "empty") {
			cout << "The SBT " << (sbt.empty() ? "is" : "isn't") << "empty" << endl;
		}
	}
	return 0;
}