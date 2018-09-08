#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;
int n, jw[10][10], alpha[128], upper[128], flag;
char g[10][10], ord[10], num[10];
inline char getch() {
	char ch = getchar();
	while (!isalpha(ch) && ch != '+') ch = getchar();
	return ch;
}
inline void getch(int i, int j) {
	char ch[3];
	scanf("%s", ch);
	if (strlen(ch) > 1) {
		jw[i][j] = 1;
		num[1] = ch[0];	//я╟ур1
		upper[ch[0]] = 1;
		g[i][j] = ch[1];
	}
	else g[i][j] = ch[0];
}
int main() {
	scanf("%d", &n);
	getch();
	for (int i = 0; i < n - 1; i++) {
		char tmp = getch();
		ord[i] = tmp;
		alpha[tmp] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		getch();
		for (int j = 0; j < n - 1; j++) getch(i, j);
	}
	//я╟ур0
	for (int i = 0; i < n - 1; i++) {
		if (g[i][i] == ord[i]) {
			num[0] = ord[i];
			upper[ord[i]] = 0;
			break;
		}
	}
	//я╟ур2~n-2
	int one = alpha[num[1]];
	for (int k = 2; k < n - 1; k++) {
		char tmp = g[one][alpha[num[k - 1]]];
		num[k] = tmp;
		upper[tmp] = k;
	}
	//╪Л╡И
	for (int i = 0; i < n - 1 && !flag; i++) {
		for (int j = 0; j < n - 1 && !flag; j++) {
			int res = upper[ord[i]] + upper[ord[j]];
			int jingwei = res / (n - 1);
			res = res % (n - 1);
			if (jingwei == jw[i][j] && num[res] == g[i][j]) continue;
			flag = 1;
		}
	}
	if (flag) puts("ERROR!");
	else {
		for (int i = 0; i < n - 1; i++)
			printf("%c=%d ", ord[i], upper[ord[i]]);
		putchar(10);
		printf("%d\n", n - 1);
	}
	return 0;
}