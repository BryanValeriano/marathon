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

ll a,b;
int gol;

ll solve(ll at, int mask) {
    if(at == a) return (mask == gol? 1 : 0);
    int ans = 0;
    for(int i = 0; i <= gol; i++) 
        ans += solve(at+1, mask | i);
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> b >> a;
    gol = pow(2,b)-1;
    cout << solve(0,0) << endl;
    return 0;
}

