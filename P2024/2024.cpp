#include<iostream>
#include<cstring>
#define open(s) ios::sync_with_stdio(false); freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin); fclose(stdout);
using namespace std;
int n,k,p[200000],ans=0;
int find(int x){
	return p[x]==x ? x : find(p[x]);
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=3*n;i++) p[i]=i;
	while (k--){
		int a,x,y;
		cin>>a>>x>>y;
		if(x>n || y>n || (x==y && a==2)){
			ans++;
			continue;
		}
		int px=find(x),py=find(y);
		if(a==1){
			if(px!=py){
				int px2=find(x+n),px3=find(x+n*2);
				if(px2!=py && px3!=py){
					int py2=find(y+n),py3=find(y+n*2);
					p[px]=py;
					p[px2]=py2;
					p[px3]=py3;
				}
				else ans++;
			}
		}
		else{
			if(px==py) ans++;
			else{
				int px2=find(x+n);
				if(px2!=py){
					int py3=find(y+2*n),py2=find(y+n),px3=find(x+n*2);
					p[px]=py2;
					p[px2]=py3;
					p[px3]=py;
				}
				else ans++; 
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
