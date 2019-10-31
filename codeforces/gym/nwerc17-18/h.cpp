#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define loop(x) for (int i = 0;i < x;i++)
#define each(x, xs) for (auto& x : xs)
#define iter(a) a.begin(), a.end()

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vi v(3);
ll d;

ll sq(ll x) { return x*x; }

ll brute() {
    ll ans = 0;

    for(int i = 0; i <= d; i++) {
        for(int j =0; j+i <= d; j++) {
            int k = d - (i+j);
            ll z = sq(v[0]+i);
            z += sq(v[1]+j);
            z += sq(v[2]+k);
            z += min({v[0]+i,v[1]+j,v[2]+k})*7ll;
            ans = max(ans,z);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    loop(n) {
        loop(3) cin >> v[i];
        sort(iter(v));
        cin >> d;
        if(d <= 1000) cout << brute() << endl;
        else {
            cout << (sq(v[0]) + sq(v[1]) + sq(v[2]+d) + 7ll*v[0]) << endl;
        }
    }
    return 0;
}

