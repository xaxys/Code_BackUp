#include <bits/stdc++.h>
#define clear(x) memset((x), 0, sizeof((x)));
using namespace std;
const int N = 5010;

class edge {
public:
    int a, b;
    bool exist;
    edge(int x, int y): a(x), b(y), exist(true) {}
    int to(int x) { return x == a ? b : a; }
};

vector<edge *> g[N];
edge* alledge[N];
int n, m;
int cnt[N];
int f[N];

void findloop() {
    clear(cnt);
    for (int i = 1; i <= n; i++) cnt[i] = g[i].size();
    while(1) {
        bool fl = false;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 1) {
                for (int j = 0; j < g[i].size(); j++) {
                    edge* e = g[i][j];
                    cnt[e->to(i)]--;
                }
                cnt[i]--;
                fl = true;
            }
        }
        if (!fl) break;
    }
}

int rec[N], ptr;
int ans[N];

bool WORSE;
bool BETTER;
void dfs(int x) {
    rec[++ptr] = x;
    if (!BETTER) {
        if (ans[ptr] < rec[ptr]) {
            WORSE = true;
            return;
        } else if (ans[ptr] > rec[ptr]) {
            BETTER = true;
        }
    }
    if (BETTER && ptr == n) {
        memcpy(ans, rec, sizeof(int) * (n + 1));
        return;
    }
    for (int i = 0; i < g[x].size() && !WORSE; i++) {
        edge *e = g[x][i];
        if (!e->exist) continue;
        int u = e->to(x);
        if (u == f[x]) continue;
        f[u] = x;
        dfs(u);
        f[u]= 0;
    }
}

int cmptmp;
bool cmp(edge* a, edge* b) {
    return a->to(cmptmp) < b->to(cmptmp);
}

int main() {
    memset(ans, 0x3f, sizeof(ans));
    clear(f);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge* e = new edge(a, b);
        g[a].push_back(e);
        g[b].push_back(e);
        alledge[i] = e;
    }
    for (int i = 1; i <= n; i++) {
        cmptmp = i;
        sort(g[i].begin(), g[i].end(), cmp);
    }
    if (m == n) {
        findloop();
        for (int i = 1; i <= m; i++) {
            edge* e = alledge[i];
            if (cnt[e->a] == 2 && cnt[e->b] == 2) {
                e->exist = false;
                ptr = 0;
                WORSE = BETTER = false;
                dfs(1);
                e->exist = true;
            }
        }
    }
    else {
        ptr = 0;
        WORSE = BETTER = false;
        dfs(1);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}