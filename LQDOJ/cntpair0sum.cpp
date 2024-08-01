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
#include <unordered_map>

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
   int n; cin >> n;
   int a[n+1];
   for (int i = 1;i <= n; ++i) cin >> a[i];
   unordered_map<int, int> mp;
	ll cnt=0;
   for (int i = 1; i <= n; ++i) {
   	cnt+=mp[-a[i]];
   	++mp[a[i]];
   }   
   cout << cnt << endl;
   return 0;
}