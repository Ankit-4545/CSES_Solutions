#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> vis, parent;
 
vector<int> get_cycle(int start, int end) {
    vector<int> path_start, path_end;
 
    int x = start;
    while (x != -1) {
        path_start.push_back(x);
        x = parent[x];
    }
 
    x = end;
    while (x != -1) {
        path_end.push_back(x);
        x = parent[x];
    }
 
    // Find first common ancestor
    int i = path_start.size() - 1;
    int j = path_end.size() - 1;
    while (i >= 0 && j >= 0 && path_start[i] == path_end[j]) {
        i--; j--;
    }
 
    vector<int> cycle;
    for (int k = 0; k <= i + 1; k++) cycle.push_back(path_start[k]);
    for (int k = j; k >= 0; k--) cycle.push_back(path_end[k]);
    cycle.push_back(start); // close the cycle
    return cycle;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    bool found = false;
    vector<int> cycle;
 
    for (int i = 1; i <= n && !found; i++) {
        if (vis[i]) continue;
        queue<int> q;
        vis[i] = 1;
        parent[i] = -1;
        q.push(i);
 
        while (!q.empty() && !found) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (neighbor == parent[node]) continue; // skip parent
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                } else {
                    // cycle detected
                    cycle = get_cycle(node, neighbor);
                    found = true;
                    break;
                }
            }
        }
    }
 
    if (!found) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cycle.size() << "\n";
        for (int c : cycle) cout << c << " ";
        cout << "\n";
    }
 
    return 0;
}
