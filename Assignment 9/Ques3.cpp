#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    a = find(a); b = find(b);
    parent[b] = a;
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n = 4; // vertices
    int m = 5; // edges
    Edge edges[] = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};

    for(int i=0;i<n;i++) parent[i] = i;

    sort(edges, edges+m, cmp);

    int cost = 0;
    cout << "Edges in MST: ";
    for(int i=0;i<m;i++) {
        if(find(edges[i].u) != find(edges[i].v)) {
            cout << "(" << edges[i].u << "," << edges[i].v << ") ";
            cost += edges[i].w;
            unionSet(edges[i].u, edges[i].v);
        }
    }
    cout << "\nTotal cost: " << cost << endl;
    return 0;
}
