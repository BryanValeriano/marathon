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

const int T = 101;
int dp[T][T][T][3];
int v[T];
int n;

int solve(int at, int impar, int par, int last) {
    if(at == n) return 0;
    int &z = dp[at][impar][par][last];
    if(~z) return z;

    int l = INF;
    int r = INF;

    if(!v[at]) {
        if(impar) l = solve(at+1,impar-1,par,1) + (1 != last);
        if(par) r = solve(at+1,impar,par-1,0) + (0 != last);
    } else l = solve(at+1,impar,par,v[at]&1) + ((v[at]&1) != last);

    return z = min(l,r);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);

    cin >> n;
    int par = n/2;
    int impar = n-par;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i]) {
            par -= ((v[i]&1) == 0);
            impar -= ((v[i]&1) == 1);
        }
    }

    cout << solve(0,impar,par,2)-1 << endl;
    return 0;
}

