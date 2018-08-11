#include <iostream>
using namespace std;
int height[20], h, s;
int main()
{
	for (int i = 0; i<10; i++) cin >> height[i];
	cin >> h;
	h += 30;
	for (int i = 0; i<10; i++) s += (h >= height[i]);
	cout << s;
}