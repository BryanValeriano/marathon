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

vector<ll> v;
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n; 
    int x;

    for(int i = 0; i < n; i++) {
        cin >> x;
        v.pb(abs(x));
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    ll acum = 0;

    for(int i = 0; i < n; i++) {
        if(i > 0 and v[i] == v[i-1]) ans -= acum, acum++;
        else acum = 1;
        ll maior = lower_bound(v.begin(), v.end(), v[i]) - v.begin();
        ll valido = lower_bound(v.begin(), v.end(), 2*v[i]+1) - v.begin();
        maior = n-maior-1;
        valido = n-valido;
        ans += (maior - valido);
    }

    cout << ans << endl;

    return 0;
}

