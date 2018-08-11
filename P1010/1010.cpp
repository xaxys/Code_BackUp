#include <iostream>
#include <string.h>
using namespace std;
int n;
void divide(int num) {
	int a[20],tmp,i=0;
	tmp = num;
	while (tmp > 0) {
		a[i++] = tmp % 2;
		tmp /= 2;
	}
	for (int j = i - 1; j >= 0; j--) {
		if (a[j] > 0) {
			if (j != i - 1) cout << "+";
			if (j == 1) cout << "2";
			else if (j == 0) cout << "2(0)";
			else {
				cout << "2(";
				divide(j);
				cout << ")";
			}
		}
	}
}
int main() {
	cin >> n;
	divide(n);
	cout << endl;
	return 0;
}