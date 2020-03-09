#include<bits/stdc++.h>
//#define debug
using namespace std;
typedef pair<int, int*> pa;
const int N = 3010;
int n, m;
struct edge {
    int to, v;
    edge(int a, int b) : to(a), v(b) {}
};
vector<edge> g[N];
int money[N];

void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - m; i++) {
        int num, to, v;
        scanf("%d", &num);
        for (int j = 1; j <= num; j++) {
            scanf("%d%d", &to, &v);
            g[i].push_back(edge(to, v));
        }
    }
    for (int i = n - m + 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        money[i] = k;
    }
}

pa dfs(int x) {
#ifdef debug
    printf("[Enter] x = %d\n", x);
#endif
    int num = 0;
    int* a = new int[N];
    memset(a, -0x7f, sizeof(int) * N);
    a[0] = 0;
    if (x > n - m) {
        num = 1;
        a[1] = money[x];
#ifdef debug
        for (int i = 0; i <= num; i++) {
            printf("a[%d] = %d, ", i, a[i]);
        }
        putchar(10);
        printf("[Exit] x = %d\n", x);
#endif
        return make_pair(num, a);
    }
    for (int i = 0; i < g[x].size(); i++) {
        int &to = g[x][i].to, &v = g[x][i].v;
        pa p = dfs(to);
        num += p.first;
        for (int j = num; j >= 0; j--) {
            for (int i = 1; i <= min(p.first, j); i++) {
                a[j] = max(a[j], p.second[i] + a[j - i] - v);
            }
        }
        delete p.second;
    }
#ifdef debug
    for (int i = 0; i <= num; i++) {
        printf("a[%d] = %d, ", i, a[i]);
    }
    putchar(10);
    printf("[Exit] x = %d\n", x);
#endif
    return make_pair(num, a);
}

int main() {
    init();
#ifdef debug
    printf("n = %d, m = %d\n", n, m);
#endif
    pa ans = dfs(1);
    int i;
    for (i = ans.first; i > 0; i--) {
        if (ans.second[i] >= 0) break;
    }
    printf("%d\n", i);
    return 0;
}