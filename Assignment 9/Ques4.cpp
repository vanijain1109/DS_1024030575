#include <iostream>
#include <climits>
using namespace std;

const int N = 100;
int graph[N][N];

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, idx;
    for(int i=0;i<n;i++)
        if(!visited[i] && dist[i] <= min) {
            min = dist[i];
            idx = i;
        }
    return idx;
}

void dijkstra(int src, int n) {
    int dist[n];
    bool visited[n];
    for(int i=0;i<n;i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;

    for(int count=0; count<n-1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for(int v=0; v<n; v++)
            if(!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Vertex distances from " << src << ": ";
    for(int i=0;i<n;i++) cout << dist[i] << " ";
    cout << endl;
}

int main() {
    int n = 5;
    // Sample weighted graph
    graph[0][1] = 10; graph[0][4] = 5;
    graph[1][2] = 1;  graph[1][4] = 2;
    graph[2][3] = 4;
    graph[3][0] = 7;  graph[3][2] = 6;
    graph[4][1] = 3;  graph[4][2] = 9;  graph[4][3] = 2;

    dijkstra(0, n);
    return 0;
}
