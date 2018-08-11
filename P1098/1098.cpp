#include<cstdio>
#include<cctype>
#include<cstring>
#define same ((isdigit(l) && isdigit(ch)) || (isupper(l) && isupper(ch)) || (islower(l) && islower(ch)))
using namespace std;
int p1, p2, p3;
char ch, l;
int main() {
	scanf("%d%d%d", &p1, &p2, &p3);
	ch = getchar();
	while (ch < 33) ch = getchar();
	while (ch != EOF) {
		if (ch == '-') {
			ch = getchar();
			char s[1000];
			memset(s, 0, sizeof(s));
			int cnt = 0;
			if (l < ch && same) {
				l++;
				for (; l < ch; l++) {
					switch (p1) {
					case 1: {
						for (int i = 0; i < p2; i++) s[cnt++] = tolower(l);
						break;
					}
					case 2: {
						for (int i = 0; i < p2; i++) s[cnt++] = toupper(l);
						break;
					}
					case 3: {
						for (int i = 0; i < p2; i++) s[cnt++] = '*';
						break;
					}
					}
				}
				if (strlen(s)) {
					if (p3 == 1) for (int i = 0; i < strlen(s); i++) putchar(s[i]);
					else for (int i = strlen(s) - 1; i >= 0; i--) putchar(s[i]);
				}
			}
			else putchar('-');
		}
		l = ch;
		putchar(ch);
		ch = getchar();
	}
	putchar(10);
	return 0;
}