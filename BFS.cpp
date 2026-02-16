#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> heuristic;

void bestFirstSearch(int start, int target, int n) {
    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({heuristic[start], start});
    visited[start] = true;

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        cout << node << " ";

        if (node == target)
            return;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                pq.push({heuristic[neighbor], neighbor});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    graph.resize(n);
    heuristic.resize(n);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
        cin >> heuristic[i];

    int target;
    cin >> target;

    bestFirstSearch(0, target, n);
}
