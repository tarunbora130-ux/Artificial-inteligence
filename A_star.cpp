#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> heuristic;

void aStar(int start, int target, int n) {
    vector<int> g(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> closed(n, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    g[start] = 0;
    pq.push({heuristic[start], start});

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (closed[node])
            continue;

        closed[node] = true;

        if (node == target)
            break;

        for (auto edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (!closed[neighbor] && g[node] + weight < g[neighbor]) {
                g[neighbor] = g[node] + weight;
                parent[neighbor] = node;
                pq.push({g[neighbor] + heuristic[neighbor], neighbor});
            }
        }
    }

    vector<int> path;
    int current = target;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    for (int node : path)
        cout << node << " ";
}

int main() {
    int n, e;
    cin >> n >> e;

    graph.resize(n);
    heuristic.resize(n);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 0; i < n; i++)
        cin >> heuristic[i];

    int start, target;
    cin >> start >> target;

    aStar(start, target, n);
}
