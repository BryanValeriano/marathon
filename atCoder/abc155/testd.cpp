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

vector<ll> v;
vector<ll> ve;
ll n,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.pb(x);
    }

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            ve.pb(v[i]*v[j]);

    sort(ve.begin(), ve.end());

    for(auto x : ve) cout << x << endl;

    return 0;
}

