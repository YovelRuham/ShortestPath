#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a graph edge
struct Edge {
    int to;      // Destination node of the edge
    int weight;  // Weight or cost of traversing the edge
};

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distance) {
    int numNodes = graph.size();
    
    // Initialize distance vector with maximum values, except for the starting node
    distance.resize(numNodes, numeric_limits<int>::max());
    distance[start] = 0;

    // Priority queue to keep track of nodes to visit, ordered by distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        // If the extracted distance is greater, skip this node
        if (currDist > distance[currNode]) continue;

        // Explore neighbors of the current node
        for (const Edge& edge : graph[currNode]) {
            int newDist = currDist + edge.weight;
            if (newDist < distance[edge.to]) {
                distance[edge.to] = newDist;
                pq.push({newDist, edge.to});
            }
        }
    }
}

int main() {
    int numNodes = 5;
    vector<vector<Edge>> graph(numNodes);

    // Adding edges to the graph
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 5});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 9});
    graph[2].push_back({4, 2});
    graph[3].push_back({4, 4});
    graph[4].push_back({0, 7});
    graph[4].push_back({3, 6});

    int startNode = 0;
    vector<int> distance;
    dijkstra(graph, startNode, distance);

    // Print the shortest distances from the start node to all other nodes
    cout << "Shortest distances from node " << startNode << ":\n";
    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": " << distance[i] << endl;
    }

    return 0;
}
