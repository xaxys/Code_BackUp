#include <stdio.h>
int main(){
	int n,i,k,x,y;
	int a[10001][4];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	}
	scanf("%d%d",&x,&y);
	k=-1;
	for(i=n;i>=0;i--){
		if( x>=a[i][1] && x<=(a[i][1]+a[i][3]) && y>=a[i][2] && y<=(a[i][2]+a[i][4]) ){k=i;break;}
	}
	printf("%d",k+1);
	return 0;
}






