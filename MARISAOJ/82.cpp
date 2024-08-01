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

typedef unsigned long long ll;

#define endl '\n'
#define allin(v) begin(v), end(v)
#define pb push_back
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)


vector<ll> hamming(1,0);
ll x, y, z;
ll max = 1e18;

ll bp(ll a, ll b) {
	if (b==0) return 1;
	ll res = bp(a, b/2);
	res=res*res;
	if (b&1) res=res*a;
	return res;
}

bool check(ll m) {
	if (m>1e18) return 0;
	while (m%2==0) m/=2;
	while (m%3==0) m/=3;
	while (m%5==0) m/=5;
	if (m!=1) return 0;
	return 1;
}

void vetcan() {
	for (ll i = 0; i <= 60; ++i) {
		x=bp(2ll, i);
		if (x>1e18) break;
		for (ll j = 0; j <= 38; ++j) {
			y=bp(3ll, j);
			if (x*y>1e18) break;
			for (ll k = 0; k <= 25; ++k) {
				z=bp(5ll, k);
				if (x*y*z>1e18) break;
				hamming.push_back(x*y*z);
			}
		}
	}
}

signed main() {
   fastIO;
	vetcan();
	sort(begin(hamming), end(hamming));
	int q; cin >> q;
	while (q--) {
		ll m; cin >> m;
		if (check(m)) {
			ll pos = lower_bound(allin(hamming), m)-hamming.begin();
			cout << pos << endl;
		} else {
			cout << -1 << endl;
		}
	}
   return 0;
}