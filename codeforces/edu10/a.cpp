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
    ll h1,h2,a,b;
    cin >> h1 >> h2 >> a >> b;
    int ini = h1-(a*4);
    if(ini + (12 * a) < h2 and 12*a <= 12*b) { cout << -1 << endl; return 0; }
    int ans = 0;
    while(ini < h2) {
        ini += 12*a;
        if(ini >= h2) { cout << ans << endl; return 0; }
        ini -= 12*b;
        ans++;
    }
    return 0;
}

