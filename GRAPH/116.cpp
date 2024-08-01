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

int n, m;
vector<int> adj[nmax];
int parent[nmax];
bool visited[nmax];

void dfs(int u) {
	visited[u]=true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			parent[v]=u;
			dfs(v);
		}
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u]=true;
	while (sz(q)!=0) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x]=true;
			}
		}
	}
}

void findpath(int s, int t) {
	memset(parent, 0, sizeof(parent));
	memset(visited, 0, sizeof(visited));
	bfs(s);
	if (!visited[t]) {
		cout << "-1 ";
	} else {
		cout << bfs;
	}
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m; 
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y); adj[y].pb(x);
   }
   for (int i = 2; i <= n; ++i) findpath(1, i);
   return 0;
}