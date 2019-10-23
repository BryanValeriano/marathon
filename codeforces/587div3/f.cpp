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
const ll INF = 1e12;

const int T = 2e5 + 5;
int n,k;
string s;
ll dp[T];
ll x[T];

 
int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 1; i < T; i++) dp[i] = INF;
    cin >> n >> k >> s;
    s = '0' + s;
    int at = 0;
    ll min = INF;
    for(int i = 1; i <= n; i++) {
        dp[i] += min(dp[i], dp[i-1] + i+1);
        if(i > at) min = INF;
        if(s[i] == '1') {
            

    }
    return 0;
}

