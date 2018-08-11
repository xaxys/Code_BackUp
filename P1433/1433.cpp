#include <iostream>
#include <float.h>
#include <math.h>
using namespace std;
int n;
double dis[16][16],minl=2147483647,x[16]={0},y[16]={0};
bool record[16]={1};
void dfs(double l,int k,int depth){
	if (l>minl) return;
	if (depth==n){
		minl=l;
		return;
	}
	for (int i=1;i<=n;i++){
		if (!record[i]){
			record[i]=1;
			dfs(l+dis[i][k],i,depth+1);
			record[i]=0;
		}
	}
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		record[i]=0;
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	}
	dfs(0,0,0);
	printf("%.2f\n",minl);
	return 0;
}
