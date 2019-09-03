#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const ll INF = 0x3f3f3f3f;
int n, m;
vector< pair<ll,ll> >row;

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

    ll resp = 0;
    for(int i = 0; i < n; i++) {
        if(tamanho <= m) break;
        tamanho = tamanho - row[i].fi + row[i].sec;
        resp++;
    }
    
    (tamanho <= m)? cout << resp : cout << -1;
    cout << endl;
   
    //cout << endl << endl;
    //for(pair<ll,ll> x : row) cout << x.fi << " " << x.sec << endl;

    return 0;
}
