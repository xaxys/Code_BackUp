#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
class road{
	public:
		int x,y,t;
};
int n,m,p[5001],k=0,ans=0;
road r[200001];
bool cmp(road a,road b){
	return a.t<b.t;
}
int find(int x){
	if(p[x]==x) return x;
	return find(p[x]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,t;
		cin>>r[i].x>>r[i].y>>r[i].t; 		
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		int a=find(r[i].x),b=find(r[i].y);
		if(a!=b){
			k++;
			p[a]=b;
			ans=r[i].t;
		}
	}
	if(k==n-1) cout<<ans<<endl;
	else cout<<"-1"<<endl;
	return 0;
}

