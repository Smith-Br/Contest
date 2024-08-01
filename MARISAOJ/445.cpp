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
const int nmax = 1e5;

int n, k;
int a[nmax];

int f(int mid) {
	int pos = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			if (a[j]-a[i]>mid) {
				pos+=n-j+1;
				break;
			}
		}
	}
	return pos;
}

signed main() {
   fastIO;
	cin >> n >> k;
	int maxv=0;
	for (int i = 1; i <= n; ++i) { cin >> a[i]; maxv=max(maxv, a[i]); }
	sort(a+1, a+n+1);
	int l = 0, r = maxv;
	while (r-l>0) {
		int mid = (r+l)/2;
		if (f(mid)<=k) {
			r=mid;
		} else l=mid;
	}
	cout << l;
   return 0;
}