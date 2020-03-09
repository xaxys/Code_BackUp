#include <bits/stdc++.h>
using namespace std;
const int N = 205;
class person{
public:
    int df, cf;
    bool operator < (const person &b) const {
        return cf > b.cf;
    }
} a[N];

int n;

void readin() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].df, &a[i].cf);
    }
}

inline bool judge(int a, int b, int c) {
    int x = (a + c / 2) * 100 / (a + b + c);
    return rand() % 100 > x;
}

int calcTime() {
    int que1 = 0, que2 = 0;
    int maxt = 0;
    for (int i = 1; i <= n; i++) {
        if (judge(que1, que2, a[i].df)) {
            que1 += a[i].df;
            if (maxt < que1 + a[i].cf) maxt = que1 + a[i].cf;
        } else {
            que2 += a[i].df;
            if (maxt < que2 + a[i].cf) maxt = que2 + a[i].cf;
        }
    }
    return maxt;
}

int main() {
    ios::sync_with_stdio(false);
    srand(20190518);
    readin();
    sort(a + 1, a + n + 1);
    int mint = calcTime();
    for (int i = 1; i <= 20000; i++) {
        int t = calcTime();
        if (mint > t) mint = t;
    }
    printf("%d\n", mint);
    return 0;
}