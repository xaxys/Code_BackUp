#include <iostream>
using namespace std;
int n,dui[1000000]={0};
void swap(int a,int b){
	int t;
	t=dui[a];dui[a]=dui[b];dui[b]=t;
}
int left(int a) {
	return a*2;
}
int right(int a) {
	return a*2+1;
}
void shift(int a,int i){
	int big=a;
	if (a*2<=i){
		if(dui[left(a)]>dui[a]) big=left(a);
		if( (a*2<i)&&(dui[right(a)]>dui[big]) ) big=right(a);
		if(big!=a){
			swap(a,big);
			shift(big,i);
		}
	}
}
void duisort(){
	for(int i=n/2;i>0;i--) shift(i,n);
	for(int i=n;i>1;i--){
		swap(1,i);
		shift(1,i-1);
	}
}
int main(){
	cout<<"请输入数据个数："<<endl;
	cin>>n;
	cout<<"请输入数据（以空格间隔）"<<endl;
	for(int j=1;j<=n;j++) cin>>dui[j];
	duisort();
	cout<<endl;
	for(int j=1;j<=n;j++) cout<<dui[j]<<" ";
	cout<<endl;
	return 0;
}
