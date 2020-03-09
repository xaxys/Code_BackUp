#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
const int INF = 0x3f3f3f3f;
#define clear(x) memset(x, 0, sizeof(x))
int n, m;
struct edge {
    int next, to, v;
} edges[N << 2];
int g[N], cnt, d[N], rec[N];
bool inq[N];
void addedge(int from, int to, int v) {
    edges[++cnt].next = g[from];
    g[from] = cnt;
    edges[cnt].to = to;
    edges[cnt].v = v;
}
class myqueue {
    struct node
    {
        node *next;
        int v;
    };
    node *head = NULL;
    node *tail = NULL;
public:
    bool empty() { return head == NULL; }
    void push_back(int x) {
        node *n = new node();
        n->next = NULL;
        n->v = x;
        if (tail != NULL) tail->next = n;
        else head = n;
        tail = n;
    }
    void push_front(int x) {
        node *n = new node();
        n->next = head;
        n->v = x;
        if (tail == NULL) tail = n;
        head = n;
    }
    int pop() {
        node *n = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        int x = n->v;
        delete n;
        return x;
    }
    int front() { return head->v; }
};
bool spfa(int a) {
    myqueue q;
    d[a] = 0; q.push_front(a);
    while (!q.empty()) {
        int x = q.pop(); inq[x] = 0;
        for (int i= g[x]; i != 0; i = edges[i].next) {
            edge &e = edges[i];
            int u = e.to, v = e.v;
            if (d[x] + v < d[u]) {
                d[u] = d[x] + v;
                if (!inq[u]) {
                    inq[u] = 1;
                    rec[u] = rec[x] + 1;
                    if (rec[u] >= n) return false;
                    if (!q.empty() && d[u] < d[q.front()]) q.push_front(u);
                    else q.push_back(u);
                }
            }
        }
    }
    return true;
}
int main() {
    memset(d, 0x3f, sizeof(d));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int o, a, b ,c;
        scanf("%d", &o);
        switch (o) {
            case 1:
                scanf("%d%d%d", &a, &b, &c);
                addedge(b, a, -c);
                break;
            case 2:
                scanf("%d%d%d", &a, &b, &c);
                addedge(a, b, c);
                break;
            case 3:
                scanf("%d%d", &a, &b);
                addedge(a, b, 0);
                addedge(b, a, 0);
                break;
        }
    }
    bool f = true;
    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) {
            f = spfa(i);
            if (!f) break;
        }
    }
    if (f) puts("Yes");
    else puts("No");
    return 0;
}