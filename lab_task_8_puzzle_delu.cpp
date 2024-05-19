#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;

vector<vector<int>> dir = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
}; // DURL
string s = "DURL";

vector<vector<int>> ans;
int minCost = INF;
int n;
bool f = false;

bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n; 
}

int calculateCost(vector<vector<int>>& grid) {
    int cost = 0;
    int cnt = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) continue;
            if(grid[i][j] != cnt) {
                cost++;
            }
            cnt++;
        }
    }
    return cost;
}


void printGrid(vector<vector<int>>& grid) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<grid[i][j]<<" \n"[j == n - 1];
        }
    }
    cout<<endl;
}

bool prevState(char di, int i) {
    // cout<<"PP\n";
    return (di == 'D' && s[i] == 'U') || (di == 'U' && s[i] == 'D') || (di == 'R' && s[i] == 'L') || (di == 'L' && s[i] == 'R');
}


void solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int g = 0, char di = NULL) {

    if(vis[i][j]) return;
    vis[i][j] = 1;
    // cout<<"g: "<<g<<", di: "<<di<<endl;
    // printGrid(grid);
    int cur_cost = calculateCost(grid) + g;
    if(cur_cost > minCost) return;
    // if(calculateCost(grid) == 0) {
    //     minCost = g;
    //     ans = grid;
    //     f = true;
    //     return;
    // }
    if(calculateCost(grid) == 0) {
        minCost = cur_cost;
        // cout<<"minCost: "<<minCost<<endl;
        return;
    }
        
    // if(minCost != -1) return;
    int mn = INT_MAX;
    int x, y;

    for(int d = 0; d < 4; d++) {
        int nrow = i + dir[d][0];
        int ncol = j + dir[d][1];
        if(isValid(nrow, ncol)) {
            if(prevState(di, d)) continue;

            swap(grid[i][j], grid[nrow][ncol]);
            solve(nrow, ncol, grid, vis, g + 1, s[d]);
            vis[i][j] = 0;
            swap(grid[i][j], grid[nrow][ncol]);
        }
    }
    // swap(grid[i][j], grid[x][y]);
    // solve(x, y, grid, g + 1);
}

int main () {

    n = 3;

    vector<vector<int>> grid = {
        {1, 0, 2},
        {4, 5, 3},
        {7, 8, 6}
    };

    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    vector<vector<int>> vis(3, vector<int>(3, 0));

    solve(x, y, grid, vis);

    cout<<"And guess what! the minimum cost to solve this 8 puzzle is = "<<minCost<<endl;
    // cout<<"END"<<endl;
    return 0;
}