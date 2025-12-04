#include <iostream>
using namespace std;

const int N = 100;
int adj[N][N];
bool visited[N];

void DFS(int u, int n) {
    visited[u] = true;
    cout << u << " ";
    for(int v = 0; v < n; v++) {
        if(adj[u][v] && !visited[v])
            DFS(v, n);
    }
}

int main() {
    int n = 5;
    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;

    for(int i = 0; i < n; i++) visited[i] = false;

    cout << "DFS starting from vertex 0: ";
    DFS(0, n);
    cout << endl;
    return 0;
}
