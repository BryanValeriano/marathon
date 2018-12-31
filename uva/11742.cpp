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
int n, m;
int v[8];
vii wa[8];
ll ans;

void zero() {
    for(int i = 0; i < n; i++)
        wa[i].clear();
}

void read() {
    int a,b,c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        wa[a].eb(b,c);
        wa[b].eb(a,c);
    }
}

bool check() {
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < wa[v[i]].size(); j++) {
            ii res = wa[v[i]][j];
            if(res.se > 0) {
                bool flag = true;;
                for(int k = max(0, i-res.se); k <= min(n-1, i+res.se); k++) 
                    if(v[k] == res.fi) { flag = false; break; }
                if(flag) return false;
            }
            if(res.se < 0) {
                for(int k = i; k >= 0 and k > i+res.se; k--) {
                    if(v[k] == res.fi) return false;
                }
            }
        }
    }
    return true;
}

void solve(int atual, int mask) {
    if(atual == n) { if(check()) ans++; return; }
    for(int i = 0; i < n; i++) 
        if((mask & (1<<i)) == 0) {
            v[atual] = i;
            solve(atual+1, (mask | (1<<i)));
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    while(n or m) {
        ans = 0;
        zero();
        read();
        solve(0,0);
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}

