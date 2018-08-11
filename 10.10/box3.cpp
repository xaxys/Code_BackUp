#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector> 
#define open(s) ios::sync_with_stdio(false); freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin);fclose(stdout);
using namespace std;
int n,x[10005],b[10005],p=1,ans=1;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i];
    b[1]=1;
    sort(x+1,x+1+n);
    for(int i=2;i<=n;i++){
        if(b[1]<=x[i]){
            b[1]+=1;
        }
        else{
            p++;
            b[p]=1;
        }
        sort(b+1,b+p+1);
    }
    cout<<p<<endl;
    return 0;
}
