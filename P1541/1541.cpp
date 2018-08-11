#include<iostream>
#include<cstring>
#define open(s) ios::sync_with_stdio(false); freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin);fclose(stdout);
#define max(a,b) ((a)>(b) ? (a):(b))
using namespace std;
int n,m,a[400],rest[50][50][50][50],y[5]={0};;
int main(){
	//open("tortoise");
	cin>>n>>m;
	memset(rest,0,sizeof(rest));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		y[x]++;
	}
	rest[0][0][0][0]=a[1];
	for(int i=0;i<=y[1];i++){
		for(int j=0;j<=y[2];j++){
			for(int k=0;k<=y[3];k++){
				for(int l=0;l<=y[4];l++){
					int w=i+j*2+k*3+l*4+1;
					int& ans=rest[i][j][k][l];
					if(i) ans=max(ans,rest[i-1][j][k][l]+a[w]);
					if(j) ans=max(ans,rest[i][j-1][k][l]+a[w]);
					if(k) ans=max(ans,rest[i][j][k-1][l]+a[w]);
					if(l) ans=max(ans,rest[i][j][k][l-1]+a[w]);
				}
			}
		}
	}
	cout<<rest[y[1]][y[2]][y[3]][y[4]]<<endl;
	//close;
	return 0;
}
