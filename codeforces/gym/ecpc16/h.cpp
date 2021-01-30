#include <bits/stdc++.h>
using namespace std;

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
const int T = 12;
int dp[T][T][T];

int solve() {
    for(int f = 10; f >= 1; f--)
        for(int y = 1; y <= 10; y++)
            for(int x = 1; x <= 10; x++)
                dp[f][y][x] += max({dp[f+1][y][x],dp[f][y-1][x],dp[f][y][x-1]});


    return dp[1][10][10];
}


int main() {
    ios_base::sync_with_stdio(false);
    freopen("commandos.in","r",stdin);
    int tc; cin >> tc;
    while(tc--) {
        memset(dp,0,sizeof dp);
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int f,y,x,h;
            cin >> f >> y >> x >> h;
            dp[f][y][x] += h;
        }
        cout << solve() << endl;
    }
    return 0;
}

