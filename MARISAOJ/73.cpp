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
int a[1007][1007], d[1007][1007];
signed main() {
   fastIO;
   int n , k; cin >> n >> k;
   for (int i = 1; i <= n; ++i) {
   	for (int j = 1; j <= n; ++j) {
   		cin >> a[i][j];
   	}
   }

   for (int i = 1; i <= n; ++i) {
   	for (int j = 1; j <= n; ++j) {
   		if (i-2>=0) d[i][j]=d[i-1][j-1]+d[i-1][j+1]-d[i-2][j]+a[i-1][j]+a[i][j];
   		else d[i][j]=d[i-1][j-1]+d[i-1][j+1]+a[i-1][j]+a[i][j];
   		cout << d[i][j] << " ";
   	}
   	cout << endl;
   }
   return 0;
}