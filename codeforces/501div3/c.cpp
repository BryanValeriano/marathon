#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const ll INF = 0x3f3f3f3f;
const int TAM = 1e5+3;
int n; int m;
vector< pair<ll,ll> >row;
ll dp[TAM];

ll steve(int pos, ll tamanho) {
    if(tamanho <= m) return 0;
    if(pos >= n) return INF;
    if(dp[pos] != -1) return dp[pos];
    
    ll R = steve(pos + 1, tamanho - row[pos].fi + row[pos].sec) + 1;
    ll L = steve(pos + 1, tamanho);

    return dp[pos] = min(R,L);
}

bool cmp(pair<ll,ll>&a, pair<ll,ll>&b) {
    ll diffa = a.fi - a.sec;
    ll diffb = b.fi - b.sec;
    return(diffa > diffb);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ll tamanho = 0;
    for(int i = 0; i < n; i++) {
        ll a; ll b; 
        cin >> a >> b; 
        tamanho += a;
        row.pb(mk(a,b));
    }
    sort(row.begin(), row.end(), cmp);
    memset(dp, -1, sizeof dp);
    ll resp = steve(0, tamanho); 
    (resp < INF)? cout << resp : cout << -1;
    cout << endl;

    return 0;
}

