/*
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int N = 50010;
struct edge {
    int to, v, nxt;
};
int cnt;
edge edges[N << 1];
int head[N];

void addedge(int x, int y, int v) {
    edges[++cnt].to = y;
    edges[cnt].v = v;
    edges[cnt].nxt = head[x];
    head[x] = cnt;
}

int n, m;

class calc {
    int CNT;
    int MIN_LEN;
    int f[N];
    int dfs(int x) {
        vector<int> a;
        for (int i = head[x]; i ; i = edges[i].nxt) {
            const int& u = edges[i].to;
            if (u == f[x]) continue;
            const int& v = edges[i].v;
            f[u] = x;
            int tmp = dfs(u);
            if (tmp + v >= MIN_LEN) CNT++; 
            else a.push_back(tmp + v);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) {
            int& k = a[i];
            if (k == 0) continue;
            for (int j = i + 1; j < a.size(); j++) {
                int& l = a[j];
                if (k + l >= MIN_LEN) {
                    k = l = 0;
                    CNT++;
                    break;
                }
            }
        }
        int tmp = 0;
        for (int i = a.size() - 1; i > -1; i--) {
            if (a[i]) {
                tmp = a[i];
                break;
            }
        }
        return tmp;
    }
public:
    calc() {
        CNT = 0;
        MIN_LEN = 0;
        memset(f, 0, sizeof(f));
    }
    int run(int v) {
        MIN_LEN = v;
        dfs(1);
        return CNT;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        addedge(a, b, v);
        addedge(b, a, v);
    }
    int l = 0, r = 10000 * 50000;
    int ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        calc* c = new calc();
        int res = c->run(mid);
        delete c;
        if (res >= m) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    printf("%d", ans);
    return 0;
}
*/
/*
#include <bits/stdc++.h>
#define clear(x) memset(x, 0, sizeof(x));

using namespace std;
const int N = 50010;
struct edge {
    int to, v;
    edge* nxt;
    edge(int a, int b) : to(a), v(b) {
        nxt = NULL;
    }
};
edge* head[N];

void addedge(int x, int y, int v) {
    edge* e = new edge(y, v);
    e->nxt = head[x];
    head[x] = e;
}

int n, m;

class calc {
    int CNT;
    int MIN_LEN;
    int val[N];
    int f[N], dfn, seq[N];
    void dfs(int x) {
        seq[++dfn] = x;
        //cerr << "dfs = " << x << "dfn = " << dfn << " now" << endl;
        for (edge* e = head[x]; e != NULL; e = e->nxt) {
            const int &u = e->to;
            if (u == f[x]) continue;
            f[u] = x;
            dfs(u);
        }   
    }

public:
    calc() {
        CNT = 0;
        MIN_LEN = 0;
        clear(f);
        clear(val);
        clear(seq);
    }
    int run(int v) {
        MIN_LEN = v;
        dfs(1);
        for (int i = dfn; i; i--) {
            int a[N], cnt = 0;
            int x = seq[i];
            for (edge *e = head[x]; e != NULL; e = e->nxt) {
                const int &u = e->to;
                if (u == f[x]) continue;
                const int &v = e->v;
                if (val[u] + v >= MIN_LEN) CNT++;
                else a[cnt++] = val[u] + v;
            }
            sort(a, a + cnt);
            for (int i = 0; i < cnt; i++) {
                int &k = a[i];
                if (!k) continue;
                for (int j = i + 1; j < cnt; j++) {
                    int &l = a[j];
                    if (k + l >= MIN_LEN) {
                        k = l = 0;
                        CNT++;
                        break;
                    }
                }
            }
            int tmp = 0;
            for (int i = cnt - 1; ~i; i--) {
                if (a[i]) {
                    val[x] = a[i];
                    break;
                }
            }
        }
        return CNT;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        addedge(a, b, v);
        addedge(b, a, v);
    }
    int l = 0, r = 10000 * 50000;
    int ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        //cerr << "Testing mid = " << mid << " l = " << l << ", r = " << r << endl;
        calc *c = new calc();
        int res = c->run(mid);
        delete c;
        if (res >= m)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d", ans);
    return 0;
}
*/