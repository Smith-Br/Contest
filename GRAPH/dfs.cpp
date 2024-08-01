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

/*
Pseudocode
// bat dau duyet tu dinh u
void dfs(int u) {
	<THAM DINH u>
	visited[u]=true; // danh dau la u da duoc tham;
	for(v : adj[u]) {
		if (!visited[v]) dsf(v);
	}
}*/

int n, m;
vector<int> adj[1007];
bool visited[1007];

void dfs(int u) {
	cout << u << " ";
	visited[u]=1;
	for (int v : adj[u]) {
		if (!visited[v]) dfs(v);
	}
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y);
   }
   dfs(1);
   return 0;
}