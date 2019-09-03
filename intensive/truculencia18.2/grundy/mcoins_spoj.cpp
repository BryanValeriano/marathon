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
const int T = 1e6 + 10;
int a,b;

int dp[T];

int mex(int pos, int step) {
    if(pos - step >= 0) return !dp[pos-step];
    else return 0;
}

void pre() {
    dp[0] = 0;
    for(int i = 1; i < T; i++) 
        dp[i] = max({mex(i,a), mex(i,b), mex(i,1)});
}

int main() {
    ios::sync_with_stdio(false);
    int x,tc;
    cin >> a >> b >> tc;
    pre();
    while(tc--) cin >> x, cout << (dp[x]? 'A' : 'B'); 
    cout << endl;
    return 0;
}

