#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5 + 3;

int dp[T][3][3];
int vis[T][3][3];
int choose[T][3][3];
int v[T];
int n,vez;

int solve(int at, int last, int maxi) {
    if(at==n) return ((!last) and v[at]!=v[at-1]?INF:maxi);
    int &r = dp[at][last][maxi];
    if(vis[at][last][maxi] == vez) return r;
    int ans = INF;
    for(int i = 0; i < 3; i++) {
        if(i==last and v[at]!=v[at-1]) continue;
        int x = solve(at+1,i,max(maxi,i));
        if(x < ans) {
            choose[at][last][maxi] = i;
            ans = x;
        }
    }
    vis[at][last][maxi] = vez;
    return r = ans;
}

void build(int at, int last, int maxi) {
    if(at==n) {cout << endl; return; }
    cout << choose[at][last][maxi]+1 << " ";
    build(at+1,choose[at][last][maxi],max(maxi,choose[at][last][maxi]));
}


int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
        v[n] = v[0];
        if(n==1) { cout << 1 << endl << 1 << endl; continue; }
        vez++;
        cout << (solve(1,0,0)+1) << endl;
        cout << 1 << " ";
        build(1,0,0);
    }
    return 0;
}

