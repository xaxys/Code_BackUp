#include<iostream>
#include<algorithm>
#include<cstring>
#define open(s) ios::sync_with_stdio(false);freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin); fclose(stdout);
using namespace std;
class edge{
public:
	int x,y,v;
};
int n,m,p[40010];
edge edges[100010];
int cmp(edge a,edge b){
	return a.v>b.v;
}
int find(int x){
	return p[x]==x? x : find(p[x]); 
}
int main(){
	open("1525");
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>edges[i].x>>edges[i].y>>edges[i].v;
	}
	for(int i=1;i<=n*2;i++) p[i]=i;
	sort(edges,edges+m,cmp);
	for(int i=0;i<m;i++){
		int x=find(edges[i].x),y=find(edges[i].y);
		if(x==y){
			cout<<edges[i].v<<endl;
			return 0;
		}
		p[x]=find(edges[i].y+n);
		p[y]=find(edges[i].x+n);
	}
	cout<<0<<endl;
	close;
	return 0;
}
