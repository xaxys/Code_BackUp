#include <iostream>
using namespace std;
int main(){
	int l,n,i,max=0,min=0,temp;
	cin>>l>>n;
	for(i=0;i<n;i++){
		cin>>temp;
		int k,p;
		if (temp>(l/2)){
			p=temp;
			k=l-temp+1;
		}
		else{
			p=l-temp+1;
			k=temp;
		}
		if (k>min) min=k;
		if (p>max) max=p;
	}
	cout<<min<<" "<<max<<endl;
	return 0;
}
