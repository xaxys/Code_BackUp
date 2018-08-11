#include <iostream>
#include <string.h>
using namespace std;
bool shu[100], pie[100], na[100];//列和两个斜对角的控制标记
int n, ansn = 0, a[100];
void search (int i) {
	if (i == n + 1) {
		if (ansn < 3) {
			for (int o = 1; o <= n; o++) cout << a[o] << " ";
			cout << endl;
		}
		ansn++;
	}
	else {
		for (int j = 1; j <= n; j++) {
			if (!shu[j]&&!pie[i + j]&&!na[i - j + 50]) {
				a[i] = j;
				shu[j] = 1; pie[i + j] = 1; na[i - j + 50] = 1;
				search(i + 1);
				shu[j] = 0; pie[i + j] = 0; na[i - j + 50] = 0;
			}
		}
	}
}
int main() {
	memset(shu, 0, sizeof(shu));
	memset(pie, 0, sizeof(pie));
	memset(na, 0, sizeof(na));
	memset(a, 0, sizeof(a));
	cin >> n;
	search(1);
	cout << ansn << endl;
}