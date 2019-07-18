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

const int T = 103;
int v[T];
int n,k,x;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> x;
    
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) v[i] += v[i-1];
    int ans = v[n];
    int tot = ans;

    x = k*x;

    for(int i = k; i <= n; i++) 
        ans = min(ans,  tot - (v[i] - v[i-k]) + x);

    cout << ans << endl; 
    
    return 0;
}

