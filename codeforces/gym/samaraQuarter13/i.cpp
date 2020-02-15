#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;

map<ll,int> qtd;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    ll hp, dano = 0;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        ll y;
        cin >> hp >> y;

        if(hp - y - dano < 0) {
            ans++;
            if(qtd.empty()) continue;
            ii at = *qtd.rbegin();
            if(y > at.fi) continue;

            else {
                qtd[y]++;
                dano += y - at.fi;
                qtd[at.fi]--;
                if(!qtd[at.fi]) qtd.erase(at.fi);
            }
        } else qtd[y]++, dano += y;

    }

    cout << ans << endl;


    
    
    return 0;
}

