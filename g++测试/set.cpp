#include<bits/stdc++.h>
using namespace std;
int main(){
	srand((unsigned int)(time(NULL)));
	freopen("a.in","w",stdout);
	int p=rand()%101,i=1;
	for(;i<p;i++){
		cout<<rand()%101<<endl;
	}
	return 0;
}