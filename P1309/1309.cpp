#include <iostream>
#include <algorithm>
using namespace std;
class team {
public:
	int num, s, w;
};
int n, r, q;
team a[200000];
bool cmp(team a, team b) {
	if (a.s > b.s) return 1;
	else if (a.s < b.s) return 0;
	else if (a.num < b.num) return 1;
	return 0;
}
void fight() {
	int i = 0,win[200000],lose[200000],winn=-1,losen=-1,winf=0,losef=0,tempf=-1;
	team temp[200000];
	while (i < 2*n) {
		if (a[i].w > a[i + 1].w) {
			a[i].s++;
			win[++winn] = i;
			lose[++losen] = i + 1;
		}
		else {
			a[i + 1].s++;
			win[++winn] = i + 1;
			lose[++losen] = i;
		}
		i += 2;
	}
	while (winf <= winn&&losef <= losen) {
		if (a[win[winf]].s > a[lose[losef]].s) {
			temp[++tempf] = a[win[winf]];
			winf++;
		}
		else if (a[win[winf]].s < a[lose[losef]].s) {
			temp[++tempf] = a[lose[losef]];
			losef++;
		}
		else {
			if (a[win[winf]].num < a[lose[losef]].num) {
				temp[++tempf] = a[win[winf]];
				winf++;
			}
			else if (a[win[winf]].num > a[lose[losef]].num) {
				temp[++tempf] = a[lose[losef]];
				losef++;
			}
		}
	}
	if (winf > winn) {
		while (losef <= losen) {
			temp[++tempf] = a[lose[losef]];
			losef++;
		}
	}
	else if (losef > losen) {
		while (winf <= winn) {
			temp[++tempf] = a[win[winf]];
			winf++;
		}
	}
	for (i = 0; i < 2 * n; i++) a[i] = temp[i];
}
int main() {
	cin >> n >> r >> q;
	for (int i = 0; i < 2 * n; i++) {
		a[i].num = i + 1;
		cin >> a[i].s;
	}
	for (int i = 0; i < 2 * n; i++) cin >> a[i].w;
	sort(a, a + 2*n, cmp);
	for (int i = 0; i < r; i++) fight();
	cout << a[q - 1].num << endl;
}