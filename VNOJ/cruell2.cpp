#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file(name) if (fopen(name".in","r")) { freopen(name".in","r",stdin); freopen(name".out","w",stdout); }

const double EPS = 1E-6;
const int INF = 1000000000;
const ll INF64 = (ll) 1E18;
const double PI = 3.1415926535897932384626433832795;

int d;
double a[20];

double bp(double a, int b) {
	if (b==0) return 1;
	double res = bp(a, b/2);
	res = res*res;
	if (b&1) res = res*a;
	return res;
}

double f(double mid) {
	double ans=0;
	for (int i = 0; i <= d; ++i) {
		ans+=a[i]*bp(mid, i);
	}
	return ans;
}

signed main() {
   fastIO;
   cin >> d;
	for (int i = 0; i <= d; ++i) cin >> a[i];
	double l = -1e6, r = 1e6, eps=1e-6;
	while (r-l>eps) {
		double mid = l + (r-l)/2;
		if (f(mid)*f(l)<=0) {
			r = mid;
		} else l = mid;
	}
	cout << ll(1000*l) << endl;
   return 0;
}