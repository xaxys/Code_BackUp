#include <iostream>
#include <algorithm>
using namespace std;

class competition{
	public:
	int begin,end;
};

bool cmp(competition a,competition b){
	return a.end<b.end;
}
int main(){
	int n,i,j,ans=0,now=0;
	competition a[1000000];
	cin>>n;
	for(i=0;i<n;i++) cin>>a[i].begin>>a[i].end;
	sort(a,a+n,cmp);
	for (i=0;i<n;i++){
		if(now<=a[i].begin){
			ans++;
			now=a[i].end;
		}
	}
	cout<<ans<<endl;
}
