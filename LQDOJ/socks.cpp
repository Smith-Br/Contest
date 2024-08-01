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

int cnt[1007]={0};

signed main() {
   fastIO;
   int n; cin >> n;
   for (int i = 1; i <= n; ++i) {
   	int x; cin >> x;
   	++cnt[x];
   }
   int ans = 0;
   for (int i = 1; i <= 100; ++i) ans+=cnt[i]/2;
   cout << ans << endl;
   return 0;
}