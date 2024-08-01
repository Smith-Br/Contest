#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        set<int> set1, set2;
        unordered_map<int, int> vertexColor; 

        cout << "Bob" << endl;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            int v, c;
            cin >> v; // vertex to color

            set<int> *current_set, *target_set;
            if (vertexColor.count(v)) {
                current_set = (vertexColor[v] == 1) ? &set1 : &set2;
                target_set = (current_set == &set1) ? &set2 : &set1;
            } else { // first move
                c = a; 
                target_set = &set1;
            }

            for (int neighbor : graph[v]) {
                if (target_set->count(neighbor)) {
                    c = vertexColor[neighbor]; 
                    break;
                }
            }

            vertexColor[v] = c;
            target_set->insert(v);

            cout << v << " " << c << endl; 
        }
    }
    return 0;
}
