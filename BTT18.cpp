#include <iostream>
#include <cstring> // For memset
using namespace std;

#define MAX_VERTICES 100
#define MAX_EDGES 100

class GraphList {
    int V;                              // Number of vertices
    int adj[MAX_VERTICES][MAX_EDGES];   // Adjacency list as a 2D array
    int degree[MAX_VERTICES];           // Degree of each vertex (number of neighbors)

public:
    GraphList(int vertices) : V(vertices) {
        memset(adj, -1, sizeof(adj));   // Initialize adjacency list with -1 (no edges)
        memset(degree, 0, sizeof(degree));
    }

    void addEdge(int u, int v) {
        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;  // Undirected graph
    }

    void BFS(int start) {
        bool visited[MAX_VERTICES] = {false};
        int queue[MAX_VERTICES];
        int front = 0, rear = 0;

        queue[rear++] = start;
        visited[start] = true;

        cout << "BFS Order: ";
        while (front < rear) {
            int node = queue[front++];
            cout << node << " ";

            for (int i = 0; i < degree[node]; i++) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < degree[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        bool visited[MAX_VERTICES] = {false};
        cout << "DFS Order: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int V = 13; // Number of vertices
    GraphList g(V);

    // Add edges (based on the graph in the image)
    g.addEdge(0, 1);  // D1
    g.addEdge(0, 2);  // D2
    g.addEdge(0, 3);  // D3
    g.addEdge(0, 4);  // D4
    g.addEdge(0, 5);  // D5
    g.addEdge(5, 6);  // D6
    g.addEdge(6, 7);  // D7
    g.addEdge(0, 8);  // D8
    g.addEdge(8, 9);  // D9
    g.addEdge(9, 10); // D10
    g.addEdge(9, 11); // D11
    g.addEdge(11, 12);// D12
    g.addEdge(0, 12); // D13

    g.BFS(0);  // BFS starting from vertex 0
    g.DFS(0);  // DFS starting from vertex 0

    return 0;
}
