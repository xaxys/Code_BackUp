#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int main() {
	a.clear();
	a[3] = 4;
	a[9] = 10;
	a[50] = 777;
	for (int i = 1; i < 60; i++) cout << i << " " << a[i] << endl;
	return 0;
}