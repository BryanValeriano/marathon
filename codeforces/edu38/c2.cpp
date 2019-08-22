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

ll x;

int main() {
    ios::sync_with_stdio(false);

    int q; cin >> q;

    while(q--) {
        cin >> x;
        bool flag = 1;
        if(x == 0) { cout << "1 1" << endl; continue; }

        for(ll i = 0; i <= 100 and flag; i++) {
            ll tent = sqrt(x)+i;
            ll precisa = (tent*tent) - x;
            if(precisa == 0) continue;

            if((ll)sqrt(precisa) * (ll)sqrt(precisa) == precisa) {
                ll ok = (ll)sqrt(precisa);
                if(ok > tent/2) continue;
                if(tent*tent - ok*ok == x) {
                    cout << tent << " " << tent/ok << endl;
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) cout << -1 << endl;
    }

    return 0;
}

