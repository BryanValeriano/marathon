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
    long double x = 0;
    long double d = 0;
    long double t = 0;
    long double n, m;
    cin >> n >> m;
    int aux1, aux2;
    long double ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> aux1 >> aux2;
        x += aux1;
        if(aux2 > 0) d += aux2;
        else t += aux2;

    }
    int mid = n/2;
    if((int)n & 1) mid++;
    for(int i = 0; i < n; i++) { ans += x + (d*i) + (t * (abs((i+1) - mid))); }
    if(ans != 0) cout << fixed << setprecision(6) <<  ans/n << endl;
    else cout << fixed << setprecision(6) << ans << endl;
    return 0;
}

