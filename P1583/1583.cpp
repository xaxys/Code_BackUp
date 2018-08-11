#include <iostream>
#include <algorithm>
using namespace std;
class people{
	public:
		int n,w;
};
bool cmp(people a,people b){
	if (a.w>b.w) return 1;
	else if(a.w<b.w) return 0;
	else if(a.n<b.n) return 1;
	return 0;
}
int main(){
	people p[20000];
	int i,j,n,k,e[10];
	cin>>n>>k;
	for(i=0;i<10;i++) cin>>e[i];
	for(i=0;i<n;i++){
		p[i].n=i+1;
		cin>>p[i].w;
	}
	sort(p,p+n,cmp);
	for(i=0;i<n;i++) p[i].w+=e[i%10];
	sort(p,p+n,cmp);
	for(i=0;i<k;i++) cout<<p[i].n<<" ";
	return 0;
}
