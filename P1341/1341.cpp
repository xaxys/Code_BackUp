#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
int n, calc[52], t = 1, rec[52];
bool g[52][52];
int toInt(char ch) {
	if (isupper(ch)) return ch - 'A';
	return ch - 'a' + 26;
}
char toChar(int x) {
	if (x < 26) return (char)(x + 'A');
	return (char)(x + 'a' - 26);
}
void dfs(int x) {
	if (t > n + 1) return;
	for (int i = 0; i < 52; i++) {
		if (g[x][i]) {
			printf("%c", toChar(i));
			g[x][i] = 0;
			g[i][x] = 0;
			t++;
			dfs(i);
			break;
		}
	}
	if (t > n + 1) return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n;) {
		char ch1=getchar();
		if (isalpha(ch1)) {
			char ch2 = getchar();
			int int1 = toInt(ch1), int2 = toInt(ch2);
			g[int1][int2]++;
			g[int2][int1]++;
			calc[int1]++;
			calc[int2]++;
			i++;
		}
	}
	int o = 0;
	for (int i = 0; i < 52; i++) if (calc[i] % 2) { o++; rec[o] = i; }
	if (o == 0) {
		int st=0;
		bool f = 1;
		for (int i = 0; i < 52 && f; i++) {
			for (int j = 0; j < 52; j++) {
				if (g[i][j]) {
					st = i;
					f = 0;
					break;
				}
			}
		}
		printf("%c", toChar(st));
		dfs(st);
	}
	else if (o == 2) {
		int st = min(rec[1], rec[2]);
		printf("%c", toChar(st));
		dfs(st);
	}
	else {
		printf("No Solution");
	}
	puts("\n");
	return 0;
}