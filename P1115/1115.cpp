#include <iostream>
using namespace std;
int main() {
	int n, a[2010], max=-2147483647,tmp=0;
	cin >> n;
	while (n--) {
		int read;
		cin >> read;
		tmp += read;
		if (tmp > max) max = tmp;
		if (tmp < 0) tmp = 0;
	}
	cout << max << endl;
}