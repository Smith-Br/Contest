#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define allin(v) begin(v), end(v)
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file(name) if (fopen(name".in","r")) { freopen(name".in","r",stdin); freopen(name".out","w",stdout); }

const int nmax = 1e5+7;

double v[nmax], w[nmax], c[nmax];
int n, k;
bool cmp(double x, double y) { return x > y; }
bool check(double mid) {
	double s = 0;
	for (int i = 1; i <= n; ++i) {
		c[i] = v[i] - mid * w[i];
	}
	sort(c+1, c+n+1, cmp);
	for (int i = 1; i <= k; ++i) s+=c[i];
	return s>0;
}

signed main() {
   fastIO;
	cin >> n >> k;
	for (int i=1;i<=n;++i) cin >> v[i] >> w[i];
	double l = 0, r = 1e9+7, eps=1e-6;
	while (r-l>eps) {
		double mid = l+(r-l)/2;
		if (check(mid)) {
			l=mid;
		} else r=mid;
	}
	cout << setprecision(6) << fixed << r << endl;
   return 0;
}
