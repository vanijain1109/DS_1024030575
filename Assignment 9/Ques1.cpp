#include <iostream>
#include <queue>
using namespace std;

const int N = 100;
int adj[N][N]; // adjacency matrix
bool visited[N];

void BFS(int start, int n) {
    for(int i = 0; i < n; i++) visited[i] = false;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v = 0; v < n; v++) {
            if(adj[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 5; // number of vertices
    // Sample edges
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;

    cout << "BFS starting from vertex 0: ";
    BFS(0, n);
    cout << endl;
    return 0;
}
