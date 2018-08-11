#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
class pid{
public:
	int num,time,level;
	bool operator < (const pid& b) const{
		if (level!=b.level) return level<b.level;
		return num>b.num;
	}
} x;
priority_queue<pid> que;
int main(){
	int arrive,t;
	freopen("2278.in","r",stdin);
	freopen("2278.out","w",stdout);
	while(scanf("%d%d%d%d",&x.num,&arrive,&x.time,&x.level)==4){
		while(!que.empty()){
			pid now=que.top();
			que.pop();
			if(t+now.time<=arrive){
				t+=now.time;
				printf("%d %d\n",now.num,t);
			}
			else{
				now.time-=arrive-t;
				que.push(now);
				break;
			}
		}
		que.push(x);
		t=arrive;
	}
	while(!que.empty()){
		pid now=que.top();
		que.pop();
		t+=now.time;
		printf("%d %d\n",now.num,t);
	}
	return 0;
}
