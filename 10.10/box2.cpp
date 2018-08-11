#include<iostream>
#include<cstring>
#include<algorithm>
#define open(s) ios::sync_with_stdio(false); freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin);fclose(stdout);
using namespace std;
int n,x[5010],done[5010],ans=0,ling=0,k=1;;
int cmp(int a,int b){
	return a>b;
}
int next(){
	int i=1;
	for(;i<=k;i++){
		if(!done[i]) break;
	}
	if(i==k+1) return 0;
	return i;
}
int main(){
	open("box");
	memset(done,0,sizeof(done));
	cin>>n;
	while(k<=n-ling){
		int p;
		cin>>p;
		if(p==0){
			ling++;
			continue;
		}
		x[k]=p;
		k++;
	}
	k--;
	sort(x+1,x+k+1,cmp);
	int t=next();
	//cout<<k<<endl;
	do{
		int maxn=x[t];
		done[t]=1;
		for(int i=t;i<=k;i++){
			if(!done[i]&&maxn){
				done[i]=1;
				maxn=min(maxn-1,x[i]);
			}
			if(!maxn) break;
		}
		ans++;
		t=next();
		//for(int i=1;i<=k;i++) if(done[i]) cout<<x[i]<<" ";
		//cout<<"\n";
	} while(t);
	cout<<max(ling,ans);
	close;
	return 0;
}
