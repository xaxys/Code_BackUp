#include <iostream>
#define max(a,b) ( ((a)>(b))? (a) : (b) )
using namespace std;
const int x[]={1,0,-1,0},y[]={0,1,0,-1};
int r,c,map[101][101],ans[101][101];
int search(int a,int b){
	int i,length=1;
	if (ans[a][b]>0) return ans[a][b];
	for (i=0;i<4;i++){
		int xx=a+x[i],yy=b+y[i];
		if ( xx>0&&xx<=r && yy>0&&yy<=c && map[a][b]>map[xx][yy] ){
			length=max(length,search(xx,yy)+1);
		}
	}
	ans[a][b]=length;
	return length;
}
int main(){
	int i,j,biggest=0;
	cin>>r>>c;
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++){
			cin>>map[i][j];
			ans[i][j]=0;
		}
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++){
			ans[i][j]=search(i,j);
		}
	for (i=1;i<=r;i++)
		for (j=1;j<=c;j++){
			if (biggest<ans[i][j]) biggest=ans[i][j];
		}
	cout<<biggest<<endl;
	return 0;
}
