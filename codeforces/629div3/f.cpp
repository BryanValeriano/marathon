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
const ll INF = 2e18;
const double PI = acos(-1.0);
const int T = 2e5+2;
ll v[T], l[T], r[T];
map<int,ll> qtd;
map<int,ll> lef;
map<int,ll> ri;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        qtd[v[i]]++;
        if(qtd[v[i]]==k) { cout << 0 << endl; return 0; }
    }
    sort(v,v+n);
    for(int i = 1; i < n; i++) {
        l[i] = (v[i]-v[i-1])*(i)+l[i-1];
        lef[v[i]] = l[i];
    }
    for(int i = n-2; i >= 0; i--) {
        r[i] = (v[i+1]-v[i])*(n-i-1)+r[i+1];
        ri[v[i]] = r[i];
    }
    ll ans = INF;
    for(int i = 0; i < n; i++) {
        ll mov = min(n-k,n-qtd[v[i]]);
        ans = min(ans,lef[v[i]]+ri[v[i]]-mov);
        if(i+1 >= k) ans = min(ans,lef[v[i]]-min(i+1-k,i+1-qtd[v[i]]));
        if(n-i >= k) ans = min(ans,ri[v[i]]-min(n-i-k,n-i-qtd[v[i]]));
    }
    cout << ans << endl;
    return 0;
}

