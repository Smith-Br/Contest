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
void bfs(int u) {
	step1: khoi tao
	day u vao dinh hanh doi;
	queue<int> q;
	q.push(u);

	step 2: lap den khi hang doi rong;
	while (q.size()!=0) {
		int v = q.front();
		q.pop();
		<THAM DINH v>
		for (int x : adj[v]) {
			if (!visited[x]) { // neu x chua duoc tham
				q.push(x);
				visited[x]=true;
			}
		}
	}
}
*/

int n, m;
vector<int> adj[1007];
bool visited[1007];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u]=true;
	while (q.size()!=0) {
		int v = q.front();
		q.pop();
		cout << v << ' ';
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x]=true;
			}
		}
	}
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m;
   for (int i = 1; i <= m; ++i) {
   	int x, y; cin >> x >> y;
   	adj[x].pb(y);
   }
   bfs(1);
   return 0;
}