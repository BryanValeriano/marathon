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

ll v[3];

int main() {
    ios::sync_with_stdio(false);
    int q; cin >> q;
    ll a,b,c;

    while(q--) {
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v+3);
        ll x = v[1] - v[0];
        x = min(x,v[2]);
        v[0] += x;
        v[2] -= x;
        ll y = 0;
        if(v[2]) y += v[2]/2;
        cout << v[0] + y << endl;
    }


    return 0;
}

