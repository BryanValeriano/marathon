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

const int T = 1e5 + 2;
int dp[T *(sizeof(bool))][2];
int v[T];
int n;

ll solve(int at, bitset<T>mask) {
    
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        memset(dp, -1, sizeof dp);
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
    }
    return 0;
}

