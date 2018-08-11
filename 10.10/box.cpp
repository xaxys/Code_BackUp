#include<iostream>
#include<cstring>
#include<algorithm>
#define open(s) ios::sync_with_stdio(false); freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin);fclose(stdout);
using namespace std;
int n,x[5010],done[5010],ans=0;
int cmp(int a,int b){
	return a>b;
}
int next(){
	int i=1;
	for(;i<=n;i++){
		if(!done[i]) break;
	}
	if(i==n+1) return 0;
	return i;
}
int main(){
	open("box");
	memset(done,0,sizeof(done));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1,cmp);
	int t=next();
	do{
		int last=x[t];
		done[t]=1;
		for(int i=t;i<=n;i++){
			if(!done[i]&&x[i]<last){
				done[i]=1;
				last=x[i];
			}
		}
		ans++;
		t=next();
	} while(t);
	cout<<ans;
	close;
	return 0;
}
