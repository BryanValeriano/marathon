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

const int T = 1e3 + 3;
const int N = 5e5;
bitset<T> crivo;
vector<int> primes;
int dp[N];
int k;

void pre() {
    for(int i = 2; i < T; i++) {
        if(crivo[i]) continue;
        primes.pb(i);
        for(int j = i+i; j < T; j += i) crivo[j] = 1;
    }
}
        

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);

    pre();
    cin >> k;

    n = (k*(k-1))/2;
    dp[0] = 0;

    for(int i = 0; i <= n; i++) {
        if(dp[i] != i) continue;
        for(int j = 0; j < primes.size(); j++) dp[i+primes[j]] = i+1;
    }
    
    for(int i = 0; i <= n; i++) 
        if(dp[i] == k) { build(); return 0; }

    cout << -1 << endl;

    return 0;
}

