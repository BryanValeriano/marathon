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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    ll l,r; cin >> l >> r;
    ll last = 0;
    ll falta = 0;

    for(ll i = 1; i <= r; i <<= 1) if(r&i) last = i;

    for(ll i = 1; i <= last; i <<= 1) {
        if(r&i) continue;
        falta |= i;
    }


    ll tmp = 0;
    ll a,b;
    for(ll i = l; i <= r; i++)
        for(ll j = i+1; j <= r; j++)
            if((i^j) > tmp) tmp = i^j, a = i, b = j;

    cout << a << " " << b << " ";
    cout << tmp << endl;
    for(ll i = 1; i <= last; i <<= 1) cout << ((b&i)? 1 : 0);
    cout << endl;

    cout << falta << endl;
    if(falta >= l) cout << (falta^r) << endl;
    else {
        ll acum = 0;

        for(ll i = 1; i <= last; i <<= 1) {
            if(falta&i) continue;
            if(falta + acum >= l) { falta += acum; break; }
            if(falta + i >= l) { falta += i; break; }
            acum += i;
        }

        if(falta < l and falta + acum >= l) falta += acum;

        cout << (falta^r) << endl;
    }

    return 0;
}

