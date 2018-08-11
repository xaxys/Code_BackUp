#include <iostream>
using namespace std;
int main(){
	int i,n,ans=0;
	int a[1001]={0};
	cin>>n;
	for(i=0;i<n;i++){
		int read;
		cin>>read;
		if(a[read]==0) ans++;
		a[read]++;
	}
	cout<<ans<<endl;
	for(i=1;i<1001;i++) if(a[i]>0) cout<<i<<" ";
}
