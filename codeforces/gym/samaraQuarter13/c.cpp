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

const int T = 2e5 + 5;
ll v[T], k;
map<ll,ll> qtd;
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    //qtd[0]++;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
        qtd[v[i]]++;
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll need = v[i-1]; 
        ans += qtd[k+need];
        qtd[v[i]]--;
        if(!qtd[v[i]]) qtd.erase(v[i]);
    }

    cout << ans << endl;
    
    return 0;
}

