#include <iostream>
#include <string.h>
using namespace std;
const int b[10][10]={
	{0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9},
};
const int s[10][10]={ 
	{0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,9,10,9,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,8,8,8,8,7,6},   
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,6,6,6,6,6,6,6,6},
};
class pos{
public:
	int x,y,num;
	int score();
	int block();
};
int pos::score(){
	return s[x][y];
}
int pos::block(){
	return b[x][y];
}
bool recx[10][10],recy[10][10],recb[10][10];
int deep=81,maxn=0;
pos a[10][10];
void refresh(){
	int score=0;
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
			score+=a[i][j].num*a[i][j].score();
	if (score>maxn) maxn=score;
	return;
}
void dfs(int x,int y,int depth){
	int i=x,j;
	if (depth==deep){
		refresh();
		return;
	}
	bool f=0;
	for (j=y;j<=9;j++){
		if (a[x][j].num==0){
			f=1;
			break;
		}
	}
	if (f==0){
		for (i=x+1;i<=9;i++)
			for (j=1;j<=9;j++)
				if (a[i][j].num==0){
					f=1;
					break;
				}
	}
	x=i;y=j;
	bool rec[10];
	memset(rec,0,sizeof(rec));
	for (i=1;i<=9;i++){
		if (recx[x][i]==1) rec[i]=1;
		if (recy[y][i]==1) rec[i]=1;
		if (recb[a[x][y].block()][i]==1) rec[i]=1;
	}
	for (i=1;i<=9;i++){
		if (!rec[i]){
			recx[x][i]=1;
			recy[y][i]=1;
			recb[a[x][y].block()][i]=1;
			a[x][y].num=i;
			cout<<depth<<endl;
			for (int m=1;m<=9;m++){
				for (int n=1;n<=9;n++){
					cout<<a[m][n].num<<" ";
				}
				cout<<endl;
			}
			dfs(x,y,depth+1);
			recx[x][i]=0;
			recy[y][i]=0;
			recb[a[x][y].block()][i]=0;
			a[x][y].num=0;
		}
	}
	return;
}
int main(){
	memset(recx,0,sizeof(recx));
	memset(recy,0,sizeof(recy));
	memset(recb,0,sizeof(recb));
	int i,j;
	for (i=1;i<=9;i++)
		for (j=1;j<=9;j++){
			cin>>a[i][j].num;
			a[i][j].x=i;
			a[i][j].y=j;
			if (a[i][j].num>0){
				recx[i][a[i][j].num]=1;
				recy[j][a[i][j].num]=1;
				recb[a[i][j].block()][a[i][j].num]=1;
				deep--;
			}
		}
	dfs(1,1,0);
	cout<<maxn<<endl;
	return 0;
}
