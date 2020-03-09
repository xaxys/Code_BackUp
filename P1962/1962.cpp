#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const int N = 2;
const int MOD = 1000000007;
ll n;

class matrix {

public:
	ll a[N][N];
	matrix() {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < N; i++) a[i][i] = 1;
	}
	matrix operator * (const matrix& b) {
		matrix mat;
		for (int i = 0; i < N; i++) {
			for (int j = 0 ; j < N; j++) {
				mat.a[i][j] = 0;
				for (int k = 0 ; k < N; k++) {
					mat.a[i][j] += this->a[i][k] * b.a[k][j];

					mat.a[i][j] %= MOD;
				}
			}
		}
		return mat;
	}
	void operator = (const matrix& b) {
		memcpy(this->a, b.a, sizeof(b.a));

	}
	void operator *= (const matrix& b) {
		*this = *this * b;

	}
};

matrix qpow(matrix a, ll b) {
	matrix ans, base = a;
	while (b) {
		if (b&1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}

int main() {
	scanf("%lld", &n);
	matrix mat;
	mat.a[0][0] = 1; mat.a[0][1] = 1;
	mat.a[1][0] = 1; mat.a[1][1] = 0;
	matrix ans = qpow(mat, n);
	printf("%lld", ans.a[0][1]);
	return 0;
}