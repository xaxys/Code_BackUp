#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
using namespace std;
const int N=100010;
const int inf=0x3f3f3f3f;
typedef long long ll;
inline int read(){
    int r=0,f=1,c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){r=r*10+c-'0';c=getchar();}
    return r*f;
}
struct Edge{
    int to,nxt,w;
}e[N*2],E[N*2];
int head[N],Head[N],cnt=1;
void add(int u,int v,int w){
    e[cnt]=(Edge){v,head[u],w};
    head[u]=cnt;
    E[cnt]=(Edge){u,Head[v],w};
    Head[v]=cnt++;
}
int n,m,K,P;
bool inq[N];
int dis[N],f[N][51],c[N][51];
void spfa(){
    deque<int>q;
    memset(dis,63,sizeof dis);
    dis[1]=0;q.push_back(1);inq[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop_front();inq[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!inq[v]){
                    if(!q.empty()&&dis[v]<=dis[q.front()])
                    q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
}bool ff=0;
void Clear(){
    n=m=K=P=0;
    memset(inq,0,sizeof inq);
    memset(f,-1,sizeof f);
    memset(head,0,sizeof head);
    memset(Head,0,sizeof Head);
    memset(c,0,sizeof c);
    memset(e,0,sizeof e);
    memset(E,0,sizeof E);cnt=1;
    ff=0;
}
void Init(){
    n=read(),m=read(),K=read(),P=read();
    while(m--){
        int u=read(),v=read(),w=read();
        add(u,v,w);
    }
}
 
int dfs(int u,int k){
    if(~f[u][k])return f[u][k];
    c[u][k]=1;
    f[u][k]=0;
    for(int i=Head[u];i;i=E[i].nxt){
        int v=E[i].to,w=E[i].w;
        int t=dis[u]+k-w-dis[v];
        if(t<0)continue;
        if(c[v][t])ff=1;
        f[u][k]+=dfs(v,t),f[u][k]%=P;
    }
    c[u][k]=0;
    return f[u][k];
}
void Solve(){
    spfa();
    f[1][0]=1;
    int ans=0;
    for(int j=0;j<=K;j++)
    ans+=dfs(n,j),ans%=P;
    dfs(n,K+1);
    if(ff){
        cout<<-1<<endl;
        return ;
    }
    printf("%d\n",ans);
}
int main(){
	freopen("park8.in", "r", stdin); 
    int T=read();
    while(T--){
        Clear();
        Init();
        Solve();
    }
    return 0;
}
