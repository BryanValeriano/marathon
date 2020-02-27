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
typedef pair<ll,ll> frac;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

frac operator * (const frac &a, const frac &b) {
    frac ans = mk(1,1);

    ans.fi = a.fi * b.fi;
    ans.se = a.se * b.se;

    ll gcd = __gcd(ans.fi,ans.se);

    ans.fi /= gcd;
    ans.se /= gcd;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    ll v[6];
    ll tmp[6];
    for(int i = 0; i < 6; i++) cin >> v[i];
    for(int i = 0; i < 6; i++) tmp[i] = v[(i+4)%6];

    frac ans = mk(1,1);
    bool f = 0;
    bool f2 = 0;

    for(int i = 0; i < 6; i += 2) {
        frac tmp = mk(v[i+1],v[i]);

        if(v[i+1] == 0) {
            f = 1;
            continue;
        }


        ll gcd = __gcd(v[i+1],v[i]);

        tmp.fi /= gcd;
        tmp.se /= gcd;
        ans = (ans * tmp);
    }


    for(int i = 0; i < 6; i += 2) {
        bool ok = (tmp[i] == 0);
        for(int j = i+1; j < 6; j += 2) ok &= (tmp[j] != 0);
        if(ok) f2 = 1;
    }

    if(f2) cout << "Ron" << endl;
    else if(f) cout << "Hermione" << endl;
    else cout << (ans.fi > ans.se? "Ron" : "Hermione") << endl;


    return 0;
}

