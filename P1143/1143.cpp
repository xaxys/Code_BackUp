#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main() {
	int basein, baseout, num;
	vector<int> a;
	cin >> basein;
	cin >> setbase(basein) >> num;
	cin >> baseout;
	while (num != 0) {
		a.push_back(num / baseout);
		num %= baseout;
	}
	for (num=a.size-1;num>=0;num++) cout<<char()
	return 0;
}