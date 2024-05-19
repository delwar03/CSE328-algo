#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

//  A1 *  A2 *  A3 * A4
// 5*4   4*6   6*2   2*7

void solve() {
    int n = 5;
    int p[5] = {5, 4, 6, 2, 7};
    int m[5][5] = {0};
    int s[5][5] = {0};

    for(int d = 1; d < n - 1; d++) {
        for(int i = 1; i < n - d; i++) {
            int j = i + d, mn = INF;
            for(int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(cost < mn) {
                    mn = cost;
                    s[i][j] = k;
                }
            }
            m[i][j] = mn;
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            cout<<m[i][j]<<" \n"[j == n - 1];
        }
    }
    cout<<endl;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            cout<<s[i][j]<<" \n"[j == n - 1];
        }
    }
}

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

/*
i/p:  
o/p: 
*/ 