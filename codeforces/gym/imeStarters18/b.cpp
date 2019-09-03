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

const int T = 1e3 + 5;

int kit, n;
string toy[T];
int peso[T];
int dp[T][T+T];
int pega[T][T+T];
vector<string> ans;

int solve(int at, int tot) {
    if(tot <= 0) return abs(tot);
    if(at == n) return INF + INF;
    if(dp[at][tot] != -1) return dp[at][tot];

    int x = solve(at+1,tot - peso[at]);
    int y = solve(at+1, tot);

    if(x < y) pega[at][tot] = 1;

    return dp[at][tot] = min(x,y);
}

void constroi(int at, int tot) {
    if(tot < 0 or at == n) return;
    if(pega[at][tot]) {
        ans.pb(toy[at]);
        constroi(at+1, tot - peso[at]);
    } else {
        constroi(at+1, tot);
    }
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> kit >> n;

    for(int i = 0; i < n; i++) 
        cin >> toy[i] >> peso[i];

    int q; cin >> q;

    while(q--) {
        int x; cin >> x;
        x -= kit*2;
        x = x/2 + (x&1);
        if(solve(0,x) >= INF) cout << -1 << endl;
        else {
            constroi(0,x);
            cout << ans.size() << " ";
            for(auto z : ans) cout << z << " ";
            ans.clear();
            cout << endl;
        }
    }

    return 0;
}

