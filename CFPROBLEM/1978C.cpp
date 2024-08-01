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
   int tt; cin >> tt;
   while (tt--) {
   	ll n, k; cin >> n >> k;
   	ll l = 0, r;

   	if (n&1) {
   		ll even=n-1;
   		r=2*n*(n+1);
   	} else {
   		ll odd=n-1;
   		odd/=2;
   		r = 2*odd*odd;
   	}
   	
   	if (k%2==0 && k>=l && k<=r) {
   		cout << "YES" << endl;
   		if (k==r) {
   			for (int i = n; i >= 1; --i) cout << i << ' ';
   			cout << endl;
   		} else if (k==r-2) {
   			cout << n << " ";
   			for (int i = 1; i < n; ++i) cout << i << ' ';
   			cout << endl;
   		} else {
   			for (int i = 1+k/2; i >= 1; --i) cout << i << ' ';
   			for (int i = 2+k/2; i <= n; ++i) cout << i << ' ';
   			cout << endl;
   		}
   	} else { cout << "NO" << endl; }
   }
   return 0;
}