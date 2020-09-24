#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, u, v, n, m;
bool hasCycle;
char visited[N];

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void DFS(int node) {

    if(hasCycle |= visited[node] == 1) return; /** Oops, revisiting active node **/
    visited[node] = 1;                         /** current node legend mode has been activated **/

    for(int e = Head[node]; e; e = Next[e]) if(visited[To[e]] != 2)
            DFS(To[e]);

    visited[node] = 2;                          /** done with this node and mark it as visited **/
}

int main() {

    cin >> n >> m;

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
    }

    for(int node = 1; node <= n; ++node) if(!visited[node])
        DFS(node);

    cout << (hasCycle ? "YES" : "NO") << endl;
}

