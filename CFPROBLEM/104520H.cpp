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
const int nmax=1e5+7;

ll a[nmax], b[nmax];

signed main() {
   fastIO;
   int n; cin >> n;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   for (int i = 1; i <= n; ++i) a[i]=a[i]*(n-i+1)*i;
   // for (int i = 1; i <= n; ++i) cout << a[i] << " ";
   for (int i = 1; i <= n; ++i) cin >> b[i];
   sort(a+1, a+n+1);
	sort(b+1, b+n+1, greater<int>());
	ll sum=0;
	for (int i = 1; i <= n; ++i) sum+=a[i]*b[i];
	cout << sum << endl;
   return 0;
}