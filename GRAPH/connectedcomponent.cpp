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
bool visited[nmax];

void dfs(int u) {
   visited[u]=true;
   for (int v : adj[u]) {
      if (!visited[v]) dfs(v);
   }
}

void bfs(int u) {
   queue<int> q;
   q.push(u);
   visited[u]=true;
   while (q.size()!=0) {
      int v = q.front();
      q.pop();
      for (int x : adj[v]) {
         if (!visited[x]) {
            q.push(x);
            visited[x]=true;
         }
      }
   }
}

void connectedComponent() {
   ll cnt = 0;
   memset(visited, false, sizeof(visited));
   for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
         ++cnt;
         dfs(i);
      }
   }
   cout << cnt << endl;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
      int x, y; cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
   } 
   connectedComponent();
   return 0;
}