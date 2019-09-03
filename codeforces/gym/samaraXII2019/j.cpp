#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<ll> small;
vector< tuple<ll,ll,ll> > v;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    ll a,b,c;

    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        v.eb(a,b,c);
        small.pb(min({a+b, a+c, b+c}));
    }

    sort(small.begin(),small.end());

    for(int i = 0; i < n; i++) {
        tie(a,b,c) = v[i];
        ll tot = a+b+c;
        tot -= 2;
        int pos = upper_bound(small.begin(), small.end(), tot) - small.begin();
        if(min({a+b, b+c, a+c}) <= tot) pos--;
        cout << pos << " ";
    }

    cout << endl;

    return 0;
}

