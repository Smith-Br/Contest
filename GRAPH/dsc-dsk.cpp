#include <bits/stdc++.h>

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

//ds ke -> ds canh

vector<pair<int,int>> edge;
vector<int> adj[1007];

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   int n; cin >> n;
   cin.ignore();
   for (int i = 1; i <= n; ++i) {
   	string s; getline(cin, s);
   	stringstream ss(s);
   	string num;
   	while (ss >> num) {
   		if (stoi(num)>i) {
   			edge.pb({i, stoi(num)});
   		}
   	}
   }
   for (auto i : edge) cout << i.ff << " " << i.ss << endl;
   return 0;
}