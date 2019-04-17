#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 5e5 + 10;
const int N = 1e6 + 10;
vector<int> g[T];
int circle[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    int n, c; cin >> n >> c;

    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            g[i].pb(x);
        }
    }
    
    int gol = 0;

    for(int i = 1; i < n; i++) { 
        bool flag = false;
        for(int j = 0; j < min(g[i].size(), g[i-1].size()); j++) {
            if(g[i][j] != g[i-1][j]) {
                flag = true;
                if(g[i-1] < g[i]) circle[0]++, circle[c-g[i][j]+1]--, circle[c-g[i-1][j]+1]++, circle[c]--;
                else circle[c-g[i-1][j]+1]++, circle[c-g[i][j]+1]--;
                gol++;
                break;
            }
        }
        if(!flag and g[i-1].size() <= g[i].size()) flag = true;
        if(!flag) { cout << -1 << endl; return 0; }
    }

    int ans = 0;
    for(int i = 0; i < c; i++) {
        ans += circle[i];
        if(ans >= gol) { cout << i << endl; return 0; }
    }
    
    cout << -1 << endl;

    return 0;
}

