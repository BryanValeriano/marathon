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
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = (1 << 20);
const int N = 20;

int freq[N][N];
ll dp[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    char last, at; cin >> last;

    for(int i = 1; i < n; i++) { 
        cin >> at;
        freq[at-'a'][last-'a']++;
        freq[last-'a'][at-'a']++;
        last = at;
    }
    
    for(int i = 0; i < 1 << m; i++) dp[i] = INF;
    dp[0] = 0;

    for(int mask = 0; mask < 1 << m; mask++) {
        ll sum = 0;

        for(int j = 0; j < m; j++)
            if((mask >> j) & 1)
                for(int k = 0; k < m; k++)
                    if(!((mask >> k) & 1))
                        sum += freq[j][k];

        for(int j = 0; j < m; j++)
            dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + sum); 
    }
   
    cout << dp[(1 << m)-1] << endl;
    
    return 0;
}

