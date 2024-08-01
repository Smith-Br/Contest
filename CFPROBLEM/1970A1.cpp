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

bool cmp(pair<pair<int,int>,char> a, pair<pair<int,int>,char> b) {
	if (a.ff.ff==b.ff.ff) return a.ff.ss > b.ff.ss;
	return a.ff < b.ff;
}

signed main() {
   fastIO;
   string s; cin >> s;
   int sz = int(s.size());
  	vector<pair<pair<int,int>,char>> ch(sz);
  	int pref=0;
  	for (int i = 0; i < sz; ++i) {
  		ch[i].ff.ff=pref;
  		ch[i].ff.ss=i;
  		ch[i].ss=s[i];
  		if (s[i]=='(') ++pref;
  		else --pref;
  	}
  	// for (int i = 0; i < sz; ++i) cout << ch[i].ff << " ";
  	sort(begin(ch), end(ch), cmp);
  	for (int i = 0; i < sz; ++i) cout << ch[i].ss;
   return 0;
}