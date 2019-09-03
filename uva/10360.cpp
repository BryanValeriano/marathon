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
const int T = 1030;
int d,n,x,y;
ll kil[T][T];
ll ans;

void solve() {
    for(int i = 0; i <= 1024; i++)
        for(int j = 0; j <= 1024; j++) 
            if(ans < kil[i][j]) {
                    ans = kil[i][j];
                    x = i;
                    y = j;
                }
}


void read() {
    memset(kil, 0LL, sizeof kil);
    int a,b,c;
    cin >> d;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        for(int k1 = max(0, a-d); k1 <= min(1024, a+d); k1++)
            for(int k2 = max(0, b-d); k2 <= min(1024, b+d); k2++) 
                kil[k1][k2] += c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ans = 0;
        x = INF;
        y = INF;
        read();
        solve();
        cout << x << " " << y << " " << ans << endl;
    }
    return 0;
}

