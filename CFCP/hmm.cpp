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
#define pb push_back
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
const int nmax = 2e5+7;
ll n, l, r;
ll a[nmax], dp[nmax];
ll pref[nmax];

int check(ll val) {
   if (val>r || val<l) return 0;
   return 1;
}

signed main() {
   fastIO;
   int tt; cin >> tt;
   while (tt--) {
      cin >> n >> l >> r;
      for (int i = 0; i <= n; ++i) dp[i]=0;
      for (int i = 1; i <= n; ++i) {
         cin >> a[i];
         pref[i]=pref[i-1]+a[i];
      }
      for (int i = 1; i <= n; ++i) {
         // for (int j = 0; j < n; ++j) {
         //    dp[i]=max(dp[i], dp[j]+check(pref[i]-pref[j]));
         // }
         int pos = lower_bound(pref+i+1, pref+n+1, l+pref[i])-pref;
         cout << pos << " ";
      }
      cout << endl;
      for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
      cout << endl << endl;
   }
   return 0;
}