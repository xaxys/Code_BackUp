#include<iostream>
#include<cstring>
#define open(s) ios::sync_with_stdio(false); freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define close fclose(stdin);fclose(stdout);
using namespace std;
int n,k[3];
int main(){
	open("book");
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		if(x==5){
			k[1]++;
			continue;
		}
		else if(x==10){
			if(k[1]){
				k[1]--;
				k[2]++;
				continue; 
			}
			else {
				cout<<"NO";
				return 0;
			}
		}
		else if(x==10){
			if(k[2]&&k[1]){
				k[2]--;
				k[1]--;
				k[3]++;
			}
			else if(k[1]>2){
				k[1]-=3;
				k[3]++;
			}
			else{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	close;
	return 0;
}
