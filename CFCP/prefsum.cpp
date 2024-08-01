#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file(name)                                                             \
	if (fopen(name ".in", "r")) {                                                \
		freopen(name ".in", "r", stdin);                                           \
		freopen(name ".out", "w", stdout);                                         \
	}

signed main() {
	fastIO;
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<int> a(n+1);
		vector<ll> pref(n+3, 0), suff(n+3, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			pref[i]=a[i]+i;
			suff[i]=a[i]-i;
		}
		for (int i = 2; i < n-1; ++i) { pref[i]=max(pref[i], pref[i-1]); }
		for (int i = n-1; i > 2; --i) { suff[i]=max(suff[i], suff[i+1]); }
		ll ans = 0;
		for (int i = 2; i < n; ++i) {
			ans = max(ans, pref[i-1]+a[i]+suff[i+1]);
		}
		cout << ans << endl;

	}
	return 0;
}