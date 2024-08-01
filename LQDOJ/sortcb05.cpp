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

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.ff == b.ff) return a.ss > b.ss;
	return a.ff > b.ff;
}

signed main() {
   fastIO;
   int n, m; cin >> n >> m;
   pair<int, int> a[n+1];
   for (int i = 1; i <= n; ++i) cin >> a[i].ff >> a[i].ss;
   sort(a+1, a+n+1, cmp);
	cout << a[m].ff << " " << a[m].ss << endl;
   return 0;
}