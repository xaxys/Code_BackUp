#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;

class rule{
public:
	string from,to;
};
rule a[20];
int n=1;
queue<string> duiz,duin;
map<string,int> mapz,mapn;
string bg,ed;

void bfs(){
	while (!duiz.empty() && !duin.empty()){
		string zheng=duiz.front(),ni=duin.front();
		for (int i=1;i<=n;i++){
			int j=0;
			while(zheng.find(a[i].from,j)!=-1){
				int pos=zheng.find(a[i].from,j);
				zheng.replace(pos,a[i].from.size(),a[i].to);
				if (mapz[zheng]==0){
					mapz[zheng]=mapz[duiz.front()]+1;
					duiz.push(zheng);
				}
				if (mapn[zheng]!=0){
					cout<<mapz[zheng]+mapn[zheng]<<endl;
					return;
				}
				j++;
				zheng=duiz.front();
			}
			j=0;
			while(ni.find(a[i].to,j)!=-1){
				int pos=ni.find(a[i].to,j);
				ni.replace(pos,a[i].to.size(),a[i].from);
				if (!mapn[ni]){
					mapn[ni]=mapn[duin.front()]+1;
					duin.push(ni);
				}
				if (mapz[ni]!=0){
					cout<<mapz[ni]+mapn[ni]<<endl;
					return;
				}
				j++;
				ni=duin.front();
			}
		}
		duiz.pop();
		duin.pop();
	}
	cout<<"NO ANSWER!"<<endl;
}

int main(){
	cin>>bg>>ed;
	while(cin>>a[n].from>>a[n].to) n++;
	n--;
	duiz.push(bg);
	duin.push(ed);
	mapz[bg]=0;
	mapn[ed]=0;
	bfs();
	return 0;
}
