#include <iostream>
#include <algorithm>
using namespace std;
long long n,k,ans=0;
int main(){
	cin>>n>>k;
	while(n>=2){
		n/=k;
		ans+=n;
	}