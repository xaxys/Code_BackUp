#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
double ctl, alpha, kj, hd;
string name;
inline double hdz(double x) { return x * 3.14159265359 / 180.0; }
int main() {
	scanf("%*s %*s");
	cin >> name >> ctl >> alpha >> kj >> hd;
	double zz = 0.0;
	if (name.substr(0, 2) == "AP")
		zz = name.length() > 2 ? 2 : 5;
	if (kj > 3 * hd) zz *= 3;
	else if (kj > 2 * hd) zz *= 2;
	double beta = alpha - zz;
	if (beta > 70 && name.substr(0, 2) == "AP") {
		printf("We didn't penetrate their armor!\n");
		return 0;
	}
	else if (beta > 85 && name == "HEAT") {
		printf("We didn't penetrate their armor!\n");
		return 0;
	}
	double dis = hd / cos(hdz(max(0.0, beta)));
	if (dis > ctl * 1.25) printf("We didn't penetrate their armor!\n");
	else if (dis < ctl * 0.75) printf("Penetration!\n");
	else printf("Server is important~\n");
	return 0;
}