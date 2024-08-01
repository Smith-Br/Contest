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

const double EPS = 1E-9;
const int INF = 1000000000;
const ll INF64 = (ll) 1E18;
const double PI = 3.1415926535897932384626433832795;

const int nmax=2e5+7;
int a[nmax];
ll pref[nmax], prefdis[nmax];
ll suff[nmax], suffdis[nmax];
signed main() {
   fastIO;
   int n; cin >> n;
   ll ans = 1e9;
   for (int i = 1; i <= n; ++i) {
   	cin >> a[i];
   	pref[i]=pref[i-1]+a[i];
   	prefdis[i]=prefdis[i-1]+a[i]*i;
   }
   for (int i = n; i >= 1; --i) {
   	suff[i]=suff[i+1]+a[i];
   	suffdis[i]=suffdis[i+1]+a[i]*(n-i+1);
   }
   for (int i = 1; i <= n; ++i) {
   	ll res1 = prefdis[i+n/2]-prefdis[i] - i*(pref[i+n/2]-pref[i]);
   	ll res2 = suffdis[i+n/2]-suffdis[i] - i*(suff[i+n/2]-suff[i]);
   	ans = min(ans, res1+res2);
   }
   cout << ans << endl;
   return 0;
}