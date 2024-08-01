#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define file(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);

const int mod = 1e9+7;
const int nmax = 1e5+7;

ll n, k;
int a[nmax];

ll f(ll mid) {
   ll cnt=0;
   for (int i = 1; i < n; ++i) {
      int pos = lower_bound(a+i, a+n+1, mid+a[i])-a;
      cnt+=n-pos+1;
   }
   return cnt;
}

signed main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> n >> k;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   sort(a+1, a+n+1);
   int r = a[n]-a[1], l = 0;
   k = n*(n-1)/2-k+1;
   while (r-l>1) {
      int mid=l+(r-l)/2;
      if (f(mid)==k) {
         cout << mid << endl;
         return 0;
      }
      if (f(mid)<k) r=mid;
      else l=mid;
   }
   cout << l;
   return 0;
}