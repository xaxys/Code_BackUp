#include<bits/stdc++.h>
//#define debug
using namespace std;
const int N = 1010;
int n, m;
class Matrix {
    int row, col;
    //mtx 0表示有障碍, 1表示没有
    bool mtx[N][N];
public:
    Matrix(int n, int m): row(n), col(m) {}
    void getMatrix() {
        memset(mtx, 0, sizeof(mtx));
        char s[5];
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                scanf("%s", s);
                if (s[0] == 'F') mtx[i][j] = 1;
            }
        }
    }

    int solve() {
        int ans = 0;
        int up[N], left[N], right[N], lo, ro;
        for (int i = 1; i <= col; i++) {
            up[i] = left[i] = 0; right[i] = col;
        }

        for (int i = 1; i <= row; i++) {
            lo = 0;
            for (int j = 1; j <= col; j++) {
                if (!mtx[i][j]) {
                    up[j] = left[j] = 0;
                    lo = j;
                } else {
                    up[j]++;
                    left[j] = max(left[j], lo);
                }
            }
            ro = col;
            for (int j = col; j; j--) {
                if (!mtx[i][j]) {
                    right[j] = col;
                    ro = j - 1;
                } else {
                    right[j] = min(right[j], ro);
                    ans = max(ans, up[j] * (right[j] - left[j]));
                }
            }
#ifdef debug
            printf("i = %d\n", i);
            printf("j:    "); for (int j = 1; j <= col; j++) printf(" %2d ", j); putchar(10);
            printf("up:   "); for (int j = 1; j <= col; j++) printf(" %2d ", up[j]); putchar(10);
            printf("left: "); for (int j = 1; j <= col; j++) printf(" %2d ", left[j]); putchar(10);
            printf("right:"); for (int j = 1; j <= col; j++) printf(" %2d ", right[j]); putchar(10);
#endif
        }
        return ans;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    Matrix* matrix = new Matrix(n, m);
    matrix->getMatrix();
    int money = 3 * matrix->solve();
    printf("%d\n", money);
    return 0;
}