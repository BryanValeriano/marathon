#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 2;
int v[T];
int dp[T][10][10];
int vis[T][10][10];
int choose[T][10][10];
int lim, vez, n;

int solve(int at, int u, int d) {
    if(at == n) return 1;
    if(vis[at][u][d] == vez) return dp[at][u][d];

    bool l = 0;
    bool r = 0;

    if(v[at] >= u and v[at] <= lim) l |= solve(at+1,v[at],d);
    if(v[at] >= d and v[at] >= lim) r |= solve(at+1,u,v[at]);
    choose[at][u][d] = (l >= r? 1 : 0);
    vis[at][u][d] = vez;
    return dp[at][u][d] = max(l,r);
}

void build(int at, int u, int d) {
    if(at == n) return;
    if(choose[at][u][d]) {
        cout << 1;
        build(at+1,v[at],d);
    } else {
        cout << 2;
        build(at+1,u,v[at]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        string s; cin >> s;
        for(int i = 0; i < n; i++) v[i] = s[i] - '0';

        bool ok = 0;
        for(lim = 0; lim <= 9; lim++) {
            vez++;
            ok = solve(0,0,0);
            if(ok) break;
        }

        if(ok) build(0,0,0), cout << endl;
        else cout << '-' << endl;
    }
    return 0;
}

