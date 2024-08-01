#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file(name) if (fopen(name".in","r")) { freopen(name".in","r",stdin); freopen(name".out","w",stdout); }

const double EPS = 1E-9;
const int INF = 1000000000;
const ll INF64 = (ll) 1E18;
const double PI = 3.1415926535897932384626433832795;

const int nmax = 1e5+7;
int a[nmax];
ll pref[nmax], suff[nmax];
ll f[nmax], b[nmax];
signed main() {
   fastIO;
   int n; cin >> n;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   for (int i = 1; i <= n; ++i) pref[i]=pref[i-1]+a[i];
   for (int i = n; i >= 1; --i) suff[i]=suff[i+1]+a[i];

   ll f_min=0;
	for (int i = 1; i <= n; ++i) {
		f[i]=max(f[i-1], pref[i]-f_min);
		f_min=min(f_min, pref[i]);
		cout << f[i] << " ";
	}
	cout << endl;
	ll b_min=0;
	for (int i = n; i >= 1; --i) {
		b[i]=max(b[i+1], suff[i]-b_min);
		b_min=min(b_min, suff[i]);
		cout << b[i] << " ";
	}
   return 0;
}
