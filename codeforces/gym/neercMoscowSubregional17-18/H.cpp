#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<ll,ll> > vii;
const int INF = 0x3f3f3f3f;

ll t,n,m;
vii v;

ll somaMin() {
    ll ans = 0;
    ll at = v[0].fi;
    ll x = v[0].se;
    int pos = 1;
    
    while(pos < m) {
        ll d = v[pos].fi - at - 1;
        ll mod = abs(v[pos].se - x);

        if(d < mod-1) return -1; 

        ll qtd = mod - 1;
        ans += (qtd * (qtd+1))/2 + (min(x,v[pos].se) * qtd);

        if(d > mod-1) { 
            ans += min(x,v[pos].se);
            at += mod;
            d -= mod;
            ll meio = min((d/2), min(x,v[pos].se) - 1);
            ll euler = (meio * (meio+1)); 
            euler += max(0LL,(min(x, v[pos].se) - meio - 1)) * d;
            ans += euler;
        }

        x = v[pos].se;
        at = v[pos].fi;
        pos++;
    } 

    //primeira ponta
    ll d = min(v[0].fi, v[0].se) - 1;
    ans += (d * (d+1))/2 + (d * (v[0].se - d - 1));

    //ultima ponta
    d = min(n - v[m-1].fi, v[m-1].se - 1);
    ans += (d * (d+1))/2 + (d * (v[m-1].se - d - 1));

    return ans;
}

ll somaMax() {
    ll ans = 0;
    ll at = v[0].fi;
    ll x = v[0].se;
    int pos = 1;
    
    while(pos < m) {
        ll d = v[pos].fi - at - 1;
        ll mod = abs(v[pos].se - x);

        if(d < mod-1) return -1; 

        ll qtd = mod - 1;
        ans += (qtd * (qtd+1))/2 + (min(x,v[pos].se) * qtd);

        if(d > mod-1) { 
            ans += max(x,v[pos].se);
            at += mod;
            d -= mod;
            ll meio = (d/2);
            ll euler = (meio * (meio+1)); 
            euler += max(x, v[pos].se) * d;
            if(d&1) euler += meio+1;
            ans += euler;
        }

        x = v[pos].se;
        at = v[pos].fi;
        pos++;
    } 

    //primeira ponta
    ll d = v[0].fi - 1;
    ans += (d * (d+1))/2 + (d * v[0].se);

    //ultima ponta
    d = n - v[m-1].fi;
    ans += (d * (d+1))/2 + (d * v[m-1].se);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t >> n >> m;

    int x,y;
    ll sum = 0;

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        v.eb(x,y);
        sum += y;
    }

    sort(v.begin(), v.end());

    ll maxi = somaMax() + sum;
    ll mini = somaMin() + sum;

    cout << (t >= mini and t <= maxi? "Yes" : "No") << endl;
    
    return 0;
}

