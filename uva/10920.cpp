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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 2;
vii sq;

int getRing(ll n, ll p) {
    int l = 0;
    int r = sq.size()-1;
    int ans = 0;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(sq[mid].se >= p) ans = mid, r = mid-1;
        else l = mid+1;
    }

    return ans;
}

ii getSide(ll ring, ll p) {
    ll last = sq[ring].fi-1;
    ll base = sq[ring-1].se;

    int linha, col;

    //cout << base << " " << last << endl;

    if(p >= base and p <= base+last) {
        linha = sq[ring].fi;
        col = base+last+1 - p;
    }
    else if(p > base+last and p <= base+2ll*last) {
        col = 1;
        linha = base+2ll*last+1 - p;
    }
    else if(p > base+2ll*last and p <= base+3ll*last) {
        linha = 1;
        col = p - (base+2ll*last-1);
    } else {
        col = sq[ring].fi;
        linha = p - (base+3ll*last-1);
    }

    return mk(linha,col);
}

void print(int l, int c) {
    cout << "Line = " << l << ", column = " << c << ".\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n,p;
    cin >> n >> p;
    for(ll i = 1; i < T; i += 2) sq.eb(i,i*i);

    while(n and p) {
        if(p == 1) { print(n/2+1,n/2+1); cin >> n >> p; continue; }
        int ring = getRing(n,p);
        int falta = (sq[ring].fi != n? (n-sq[ring].fi) / 2 : 0);
        ii pos = getSide(ring,p);
        print(pos.fi+falta,pos.se+falta);
        cin >> n >> p;
    }
    return 0;
}

