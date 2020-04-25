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
const int T = (1 << 12);
const int K = 100;
ll dp[T][K];
ll cv[T][T];

int countInv(int mask, int pos) {
    int ans = 0;
    for(int i = 1; i < pos; i <<= 1)
        if(mask&i) ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    dp[0][0] = 1;
    for(int i = 0; i < T; i++) {
        for(int l = 1; l < T; l <<= 1) {
            if(i&l) continue;
            int inv = countInv(i,l);
            for(int j = K-1; j-inv >= 0; j--) {
                dp[i|l][j] += dp[i][j-inv];
            }
        }
    }

    int tc; cin >> tc;
    while(tc--) {
        int n,k;
        cin >> n >> k;
        cout << dp[(1<<n)-1][k] << endl;
    }

    return 0;
}

