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
#define allin(v) begin(v), end(v)
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
int n, k;
bool cmp(int a, int b) {
   if (a%k == b%k) return a < b;
   else return a%k < b%k;
}

signed main() {
   fastIO;
   int tt; cin >> tt;
   while (tt--) {
      cin >> n >> k;
      vector<int> a(n+1);
      for (int i = 1; i <= n; ++i) cin >> a[i];
      sort(a.begin()+1, a.end(), cmp);
      // for (int i = 1; i <= n; ++i) cout << a[i] << " ";
      // cout << endl;
      if (n&1) {
         vector<ll> pref(n+1, 0), suff(n+2, 0);
         for (int i = 1; i <= n; i+=2) {
            pref[i]=pref[i-1]+a[i+1]-a[i];
            pref[i+1]=pref[i];
         }
         for (int i = n; i >= 1; i-=2) {
            suff[i]=suff[i+1]+a[i]-a[i-1];
            suff[i-1]=suff[i];
         }
         ll ans = 0;
         for (int i = 1; i <= n; i+=2) {
            ans = min (ans, pref[i-1]/k + suff[i+1]/k);
            cout << ans << endl;
         }
      } else {
         ll ans = 0;
         for (int i = 2; i <= n; i+=2) {
            ans+=(a[i]-a[i-1])/k;
         }
         cout << ans << endl;
      }

   }
   return 0;
}
