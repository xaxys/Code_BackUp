#include <iostream>
#include <cmath>
using namespace std;
int m;
int main(){
	cin>>m;
	if (m%2==0){
		for (int i=int(sqrt(2*m))+1;i>=2;i--){
			if ((i%2==0)? (((2*m)%i)%2=0) : (m%i==0) ){
				cout<<(m/i)-(i/2)<<" "<<(m/i)+(i/2)<<endl;
			}
		}
	}
	else{
		for (int i=int(sqrt(2*m))+1;i>=2;i--){
			if (m%i==0){
				cout<<(m/i)-(i/2)<<" "<<(m/i)+(i/2)<<endl;
			}
		}
	}
	return 0;
}
