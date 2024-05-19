#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
int n, m, cost = 0;
vector<vector<int>> graph[N], MST;
vector<int> vis;

void solve();
void inputGraph();
void clearGraph();
void findMST();
void displayMST();

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}


void solve() {
    cin>>n>>m;

    clearGraph();
    inputGraph();
    findMST();
    displayMST();
}


void inputGraph() {
    for(int i = 0; i < m; i++) {
        int u, v, wt; cin>>u>>v>>wt;
        // u--; v--;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
}

void clearGraph() {
    for(int i = 0; i <= n; i++) {
        graph[i].clear();
    }
    vis.assign(n + 1, 0);
    cost = 0;
}

void findMST() {
    // Prims Algorithm

    set<vector<int>> st; // {wt, parent, node}
    st.insert({0, -1, 0});
    while(st.size()) {
        int node = (*st.begin())[2];
        int par = (*st.begin())[1];
        int wt = (*st.begin())[0];
        st.erase(st.begin());

        if(vis[node] == 1) continue;
        vis[node] = 1;

        if(par != -1) {
            MST.push_back({par, node});
            cost += wt;
        }
        for(auto it : graph[node]) {
            int child = it[0];
            int edgeWeight = it[1];
            if(!vis[child]) {
                st.insert({edgeWeight, node, child});
            }
        }
    }
}

void displayMST() {
    cout<<cost<<endl;
    for(auto it : MST) cout<<it[0]<<" "<<it[1]<<endl;
}

/*
i/p:  
o/p: 
*/ 