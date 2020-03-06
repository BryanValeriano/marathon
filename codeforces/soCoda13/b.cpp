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
const int T = 2e3+3;

ll g[T][T];
ll diff1[3*T];
ll diff2[3*T];
int n;

ll sum(int i, int j) {
    return diff1[i+j] + diff2[i-j+T] - g[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> g[i][j];
            diff1[i+j] += g[i][j];
            diff2[i-j+T] += g[i][j];
        }
    }


    ll ans[2] = {-1,-1};
    ll x[2],y[2];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            int pos = (i+j)&1;
            if(sum(i,j) > ans[pos]) ans[pos] = sum(i,j), x[pos] = i, y[pos] = j;
        }

    cout << ans[0]+ans[1] << endl;
    cout << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << endl;

    return 0;
}

