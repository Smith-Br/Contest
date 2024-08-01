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
const int nmax = 1e5+7;

signed main() {
   fastIO;
	string s, t; cin >> s >> t;
	int n = int(s.size());
	int k = int(t.size());
	s=" "+s; t=" "+t;
	// so luong ki tu co the o vi tri i;
	vector<vector<int>> cnt(27, vector<int>(k+7, 0));
	for (int i = 1; i <= n; ++i) {
		int ch = s[i]-96;
		if (i<n-k) {
			++cnt[ch][1];
			--cnt[ch][i+1];
		} else if (i>=n-k+1) {
			++cnt[ch][i];
			--cnt[ch][k+1];
		} else {
			++cnt[ch][1];
			--cnt[ch][k+1];
		} 
	}
	for (int i = 1; i <= 26; ++i) {
		for (int j = 1; j <= k+1; ++j) {
			cnt[i][j]+=cnt[i][j-1];
			// cout << cnt[i][j] << " ";
		}
		// cout << endl;
	}
	ll ans = 0;
	for (int i = 1; i <= k; ++i) {
		int ch = t[i]-96;
		ans += cnt[ch][i];
	}
	cout << ans << endl;
   return 0;
}