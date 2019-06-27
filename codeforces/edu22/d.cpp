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

const int T = 5e3 + 5;
int v[T];
int dp[T][10][10];
int n;

int solve(int at, int a, int b) {
    if(at == n) return (a != 9 and b != 9 ? 0 : -INF);
    int &r = dp[at][a][b];
    if(r != -1) return r;

    int x = 0;
    int y = 0;
    int z = 0;

    z = solve(at+1,a,b);
    
    if(a == 9 or abs(v[at] - a) <= 1 or (v[at] == 6 and a == 0) or(a == 6 and v[at] == 0))
        x = solve(at+1,v[at],b)+1;

    if(b == 9 or abs(v[at] - b) <= 1 or (v[at] == 6 and b == 0) or(b == 6 and v[at] == 0))
        y = solve(at+1,a,v[at])+1;

    return r = max({x,y,z});
}
 
int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= 7;
    }

    cout << max({solve(1,9,v[0]), solve(1,v[0],9), solve(0,9,9),0}) << endl;
    
    return 0;
}

