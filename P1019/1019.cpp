#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
int n, a[21][21],b[21],maxlen=0;
string word[21];
char ch;
bool can(int pos,int i,int j){
	int s=word[i].size();
	for (int k=0;k<=pos;k++){
		if (word[i][s-pos-1+k]!=word[j][k]) return 0;
	}
	return 1;
}
void dfs(int num, int length) {
	bool f = 0;
	for (int i = 1; i <= n; i++) {
		if (a[num][i] != 0 && b[i]<2) {
			f = 1;
			b[i] += 1;
			dfs(i, length - word[num].size() + a[num][i]);
			b[i] -= 1;
		}
	}
	if (f == 0 && length > maxlen) maxlen = length;
}
int main() {
	int i,j;
	cin >> n;
	for (i = 1; i <= n; i++) cin >> word[i];
	cin >> ch;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++) {
			char temp = word[i][word[i].size()-1];
			int pos = word[j].find(temp, 0);
			if (pos != -1 && pos!=word[j].size()-1 && pos!=word[i].size()-1 && can(pos,i,j) ) {
				a[i][j] = word[i].size() + word[j].size() - pos - 1;
			}
		}
	for (i = 1; i <= n; i++) {
		if (word[i][0] == ch) {
			b[i] = 1;
			dfs(i, word[i].size());
			b[i] = 0;
		}
	}
	cout << maxlen << endl;
	return 0;
}
