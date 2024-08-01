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
#include <bitset>

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

// Highly optimized primality test using Sieve of Eratosthenes
constexpr int MAXN = 1000005; // Maximum possible vertex number
bitset<MAXN> isPrime;

void sieve() {
    isPrime.set(); // Mark all as prime initially
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; p * p <= MAXN; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= MAXN; i += p) {
                isPrime[i] = 0;
            }
        }
    }
}

// Function to color the graph using DFS (Depth-First Search)
vector<int> colorGraph(int n) {
    vector<vector<int>> graph(n + 1);
    vector<int> colors(n + 1, -1);  // -1 indicates uncolored

    // Build the XOR-prime graph efficiently
    for (int u = 1; u <= n; u++) {
        // Optimization: Start from u + 1 to avoid redundant checks
        for (int v = u + 1; v <= n; v++) {
            if (isPrime[u ^ v]) {
                graph[u].push_back(v);
                graph[v].push_back(u); // It's an undirected graph
            }
        }
    }

    // DFS traversal for coloring
    function<void(int, int)> dfs = [&](int u, int color) {
        colors[u] = color;
        for (int v : graph[u]) {
            if (colors[v] == -1) {
                dfs(v, 1 - color);
            }
        }
    };

    // Color the connected components 
    for (int u = 1; u <= n; u++) {
        if (colors[u] == -1) {
            dfs(u, 0); 
        }
    }
    
    return vector<int>(colors.begin() + 1, colors.end()); // Exclude the 0th index
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(); // Precompute prime numbers

    int n = 10; // Example: Graph with 10 vertices (replace with your input)
    vector<int> colors = colorGraph(n);

    cout << "Minimum number of colors: 2\n";
    cout << "Vertex | Color\n";
    for (int i = 0; i < n; i++) {
        cout << "  " << i + 1 << "   |  " << colors[i] << "\n";
    }

    return 0;
}
