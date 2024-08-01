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

signed main() {
   fastIO;
   ll a, b; cin >> a >> b;
   if (b%3!=0) { cout << 0 << endl; return 0; }
   b/=3;
   ll minv = min(a, b);
   ll sqminv = sqrt(minv);
   ll ans = 0;
   for (ll i = 1; i*i <= minv; ++i) {
   	if (a%i==0 && b%i==0) {
   		ans += i;
   		ll p = minv/i;
   		if (p*i!=minv) ans+=p;
   	}
   }
   cout << ans << endl;
   return 0;
}