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
const int T = 1000;
int dp[T+3][T+3];

bool check(int x, int y) {
    if(x > y) swap(x,y);
    if(x < 1 or y < 1) return 0;
    if(~dp[x][y]) return dp[x][y];
    if(y == 2*x) return 1;
    return dp[x][y] = (check(x-1,y-2) or check(x-2,y-1));
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= T; i++)
        for(int j = i; j <= T; j++)
            if(check(i,j)) {
                if(i < j/2) cout << i << " " << j << " UATTTTTTTTTTTTTTTTTTT " << endl;
            }
    return 0;
}

