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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
ll fat[22];

ll choose(ll n, ll x) {
    return fat[n]/(fat[n-x]*fat[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    fat[1] = 1;
    for(ll i = 2; i < 21; i++) fat[i] = i*fat[i-1];
    ll n; cin >> n;
    if(n == 2) { cout << 1 << endl; return 0; }
    ll ans = choose(n,n/2)/2;
    ll divi = (fat[n/2])/(n/2);
    divi *= divi;
    ans *= divi;
    cout << ans << endl;
    return 0;
}

