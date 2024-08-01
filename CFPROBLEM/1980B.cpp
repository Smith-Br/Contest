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
#define allin(i) begin(i), end(i)
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

signed main() {
   fastIO;
   int tt; cin >> tt;
   while (tt--) {
   	int n, f, k; cin >> n >> f >> k;
   	vector<int> a(n+1, 0);
   	for (int i = 1; i <= n; ++i) cin >> a[i];
   	f=a[f];
   	// cout << f << endl;
   	sort(begin(a)+1, end(a), greater<int>());
   	int l=1e6, r=0;
   	for (int i = 1; i <= n; ++i) {
   		if (a[i]==f) {
   			l=min(l, i); r=max(r, i);
   		}
   	}
   	// cout << l << " " << r << endl;
   	if (k<l) {
   		cout << "NO" << endl;
   	} else if (k>=r) cout << "YES" << endl;
   	else cout << "MAYBE" << endl;
   }
   return 0;
}