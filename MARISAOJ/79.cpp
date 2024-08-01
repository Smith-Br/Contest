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
#define allin(v) begin(v), end(v)
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
signed main() {
   fastIO;
	int n, q; cin >> n >> q;
	vector<vector<int>> a(nmax, vector<int>());
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		a[x].push_back(i);
	}
	// for (int i = 1; i <= 4; ++i) {
	// 	for (int j = 0; j < a[i].size(); ++j) cout << a[i][j] << " ";
	// 	cout << endl;
	// }
	while (q--) {
		int l, r, x; cin >> l >> r >> x;
		int posl = lower_bound(allin(a[x]), l)-begin(a[x]);
		int posr = upper_bound(allin(a[x]), r)-begin(a[x]);
		// cout << posl << " " << posr << endl;
		--posr;
		cout << posr-posl+1 << endl;
	}
   return 0;
}