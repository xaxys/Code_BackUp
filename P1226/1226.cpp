#include <iostream>
using namespace std;
int b, p, k, s = 1, once;
int quickmod(int index) {
	if (index == 1) return once;
	if (index % 2 == 0) {
		int tmp = quickmod(index / 2);
		return tmp*tmp%k;
	}
	else return quickmod((index + 1) / 2)*quickmod((index - 1) / 2) % k;
}
int main() {
	cin >> b >> p >> k;
	once = b%k;
	printf("%d^%d mod %d=%d\n", b, p, k, quickmod(p));
}