#include<cstring>
#include<cstdio>
#define N 1000010
#define DEBUG true
using namespace std;
char s1[N], s2[N];
int next[N];
void makeNext(const char s[], int next[]) {
	int len = strlen(s);
	next[0] = 0;
	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && s[i] != s[j]) j = next[j - 1];
		if (s[i] == s[j]) j++;
		next[i] = j;
	}
}
void KMP(const char s1[], const char s2[], int next[]) {
	makeNext(s2, next);
	int len1 = strlen(s1), len2 = strlen(s2);
	for (int i = 0, j = 0; i < len1; i++) {
		while (j > 0 && s2[j] != s1[i]) j = next[j - 1];
		if (s2[j] == s1[i]) j++;
		if (j == len2) printf("%d\n", i - len2 + 2);
	}
	if (DEBUG)
		for (int i = 0; i < len2; i++) printf("%d ", next[i]);
}
int main() {
	scanf("%s\n%s", s1, s2);
	KMP(s1, s2, next);
	return 0;
}