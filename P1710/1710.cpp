#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 200010;
const int INF = 0x3f3f3f3f;

class edge
{
public:
    int a, b;
    bool exist;
    int to(int from)
    {
        return a == from ? b : a;
    }
} edges[M];

int n, m, q;
int fdis[N], dis[N], buman[N];
stack<edge*> sta;
vector<edge*> g[N];

void readin()
{
    freopen("test.in", "r", stdin);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        edges[i].a = a;
        edges[i].b = b;
        edges[i].exist = true;
        g[a].push_back(&edges[i]);
        g[b].push_back(&edges[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        int a;
        scanf("%d", &a);
        sta.push(&edges[a]);
        edges[i].exist = false;
    }
}

void bfs()
{
    queue<int> q;
    fdis[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); i++)
        {
            int v = g[x][i]->to(x);
            if (fdis[v] > fdis[x] + 1)
            {
                fdis[v] = fdis[x] + 1;
                q.push(v);
            }
        }
    }
}

void bfs2()
{
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); i++)
        {
            if (!g[x][i]->exist)
                continue;
            int v =g[x][i]->to(x);
            if (dis[v] > dis[x] + 1)
            {
                dis[v] = dis[x] + 1;
                q.push(v);
            }
        }
    }
}

void bfs3() {
    int time = q;
    while (!sta.empty())
    {
        edge &e = *sta.top();
        sta.pop();
        int a = e.a, b = e.b;
        e.exist = true;
        queue<int> q;
        if (dis[a] == fdis[a] && dis[b] != fdis[b])
            q.push(a);
        if (dis[b] == fdis[b] && dis[a] != fdis[a])
            q.push(b);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < g[x].size(); i++)
            {
                edge &e = *g[x][i];
                if (!e.exist)
                    continue;
                int v = e.to(x);
                if (fdis[v] == dis[x] + 1 && fdis[v] != dis[v])
                {
                    dis[v] = dis[x] + 1;
                    buman[time]++;
                    q.push(v);
                }
            }
        }
        time--;
    }
}

void printans() {
    for (int i = 1, j = 0; i <= q; i++)
    {
        j += buman[i];
        printf("%d\n", j);
    }
}

int main()
{
    readin();
    memset(fdis, 0x3f, sizeof(fdis));
    memset(dis, 0x3f, sizeof(dis));
    bfs();
    bfs2();
    bfs3();
    printans();
    return 0;
}