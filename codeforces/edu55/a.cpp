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

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll n, x, y, d;
        cin >> n >> x >> y >> d;
        if(y == x) { cout << 0 << endl; continue; }
        ll ini = INF;
        ll fim = INF;
        ll mult = INF;
        ll rest1 = INF; 
        ll rest2 = INF; 
        if(y == 1) { ini = x/d; (x%d != 0? ini++ : ini); }
        if(y == n) { fim = (n-x)/d; ((n-x)%d != 0? fim++ : fim); }
        if(y > x && (y-x) % d == 0) mult = (y-x)/d;
        if(y < x && (x-y) % d == 0) mult = (x-y)/d; 
        if(y % d == 1) { rest1 = (y-1)/d + x/d; (x%d != 0? rest1++ : rest1); }
        if((n-y) % d == 0) { rest2 = (n-y)/d + (n-x)/d; ((n-x)%d != 0? rest2++ : rest2); }
        ll mini = min( {ini,fim,mult,rest1,rest2} );
        cout << (mini == INF? -1 : mini) << endl;
        //cout << ini << " " << fim << " " << mult << " " << rest1 << " " << rest2 << endl;
    }
    return 0;
}

