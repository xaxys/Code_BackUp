#include<iostream>
#include<algorithm>
using namespace std;

class man{
	public:
	int time,num;    
};

bool cmp(man x,man y){
 return x.time<y.time;    
}

int main(){
	man a[1001];
	int n,i,j;
	double time=0;
	cin>>n;    
	for(i=1;i<=n;i++){
		cin>>a[i].time;
		a[i].num=i;             
	} 
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++) cout<<a[i].num<<" ";
	cout<<endl;
	for(i=n-1;i>=1;i--) time+=a[n-i].time*i;
	printf("%.2lf",time/n);
	return 0; 
}
