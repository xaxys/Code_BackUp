#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;
int main() {
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
	string line;
	clock_t begin=clock(), end;
	while (getline(cin, line)) {
		int sum = 0, x;
		stringstream ss(line);
		while (ss >> x) sum += x;
		cout << line << "    sum=" << sum << endl;
	}
	end = clock();
	cout << "run time=" << double(end-begin)/CLOCKS_PER_SEC << endl;
	return 0;
}
