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

int n, m, h;
int a[107][107];
bool visited[107][107];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int i, int j, int h) {
   memset(visited, 0, sizeof(visited));
   for (int k = 0; k < 4; ++k) {
      int i1 = i + dx[k];
      int j1 = j + dx[k];
      if (i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]>h && !visited[i1][j1]) {
         visited[i1][j1]=true;
         bfs(i1, j1, h);
      }
   }
}

bool connectedComponent() {
   memset(visited, 0, sizeof(visited));
   int cnt=0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         if (a[i][j]>h && !visited[i][j]) {
            bfs(i, j, h);
            ++cnt;
         }
      }
   }
   return cnt<=1;
}

signed main() {
   cin.tie(nullptr)->sync_with_stdio(false);   
   cin >> n >> m;
   while (n>0 && m>0) {
      for (int i = 1; i <= n; ++i) {
         for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
         }
      }

   int l = 0, r = 1000;
   while (r-l>1) {
      h = (l+r)/2;
      if (connectedComponent()) r=h;
      else l=h;
   }
   cout << l << endl;
   cin >> n >> m;
   }
   return 0;
}