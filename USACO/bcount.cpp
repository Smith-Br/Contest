#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define fastIO cin.tie(nullptr)->sync_with_stdio(false);
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file(name) if (fopen(name".in","r")) { freopen(name".in","r",stdin); freopen(name".out","w",stdout); }

signed main() {
   fastIO;
   file("bcount");
   int n, q; cin >> n >> q;
   vector<int> a(n+1);
   vector<vector<int>> cnt(4, vector<int>(n+1, 0));
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      cnt[1][i]=cnt[1][i-1];
      cnt[2][i]=cnt[2][i-1];
      cnt[3][i]=cnt[3][i-1];
      cnt[a[i]][i]=cnt[a[i]][i-1]+1;
   }
   while (q--) {
      int l, r; cin >> l >> r;
      cout << cnt[1][r]-cnt[1][l-1] << " ";
      cout << cnt[2][r]-cnt[2][l-1] << " ";
      cout << cnt[3][r]-cnt[3][l-1] << " ";
      cout << endl;
   }
   return 0;
}