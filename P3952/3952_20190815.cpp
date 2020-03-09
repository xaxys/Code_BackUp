#include<bits/stdc++.h>
using namespace std;
class Loop {
public:
    string name;
    int cpx;
    int maxSubCpx;
    bool conduct;
    Loop() {
        maxSubCpx = 0;
    }
};
class LoopManager {
    stack<Loop *> loop;
    set<string> nameManager;
public:
    Loop *main;
    bool *SYNTAX_ERROR;
    LoopManager() {
        main = new Loop();
        main->name = "main";
        AddLoop(main);
    }
    ~LoopManager() {
        while(!loop.empty()) {
            delete loop.top();
            loop.pop();
        }
    }
    void AddLoop(Loop *l) {
        int f = nameManager.count(l->name);
        if (f) {
            *SYNTAX_ERROR = true;
        } else {
            nameManager.insert(l->name);
            loop.push(l);
        }
    }
    void DeleteLoop() {
        if (Empty()) {
            *SYNTAX_ERROR = true;
        } else {
            Loop *l;
            l = loop.top();
            int cpx;
            if (l->conduct) {
                cpx = l->maxSubCpx + l->cpx;
            } else {
                cpx = 0;
            }
            nameManager.erase(l->name);
            loop.pop();
            delete l;

            l = loop.top();
            if (cpx > l->maxSubCpx) l->maxSubCpx = cpx;
        }
    }
    bool Empty() {
        return loop.size() == 1;
    }
};
class Runtime {
public:
    int line;
    int cur;
    vector<string> ctx;
    bool SYNTAX_ERROR;
    LoopManager lm;
    Runtime() {
        lm.SYNTAX_ERROR = &SYNTAX_ERROR;
        SYNTAX_ERROR = false;
        cur = 0;
    }
    int ParseCpx() {
        while (cur < line && !SYNTAX_ERROR) {
            string s = ctx[cur++];
            stringstream ss(s);
            string key;
            ss >> key;
            if (key == "E") {
                lm.DeleteLoop();
            } else if (key == "F") {
                Loop *l = new Loop();
                string var, a, b;
                ss >> var >> a >> b;
                l->name = var;
                int x = 9999, y = 9999;
                if (a != "n") x = atoi(a.c_str());
                if (b != "n") y = atoi(b.c_str());
                l->conduct = x <= y;
                l->cpx = (a != "n") && (b == "n");
                lm.AddLoop(l);
            }
        }
        if (SYNTAX_ERROR || !lm.Empty()) {
            return -1;
        } else {
            return lm.main->maxSubCpx;
        }
    }

};

void parseInfo(int &n, int &cpx, string s) {
    char ch[3];
    sscanf(s.c_str(), "%d O(%[^0-9]%d)", &n, ch, &cpx);
    if (strlen(ch) == 0) {
        cpx = 0;
    }
}

int main() {
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
        Runtime *rt = new Runtime();

        string info;
        getline(cin, info);
        int n, cpx;
        parseInfo(n, cpx, info);
        
        rt->line = n;
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);
            rt->ctx.push_back(s);
        }

        int res = rt->ParseCpx();
        if (res < 0) {
            puts("ERR");
        } else if (res == cpx) {
            puts("Yes");
        } else {
            puts("No");
        }
        delete rt;
    }
    return 0;
}