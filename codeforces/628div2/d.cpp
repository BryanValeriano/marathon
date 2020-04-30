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
const int T = 70;
ll ans[T];
ll vals[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll u,v;
    cin >> u >> v;
    if(u > v or ((v-u)&1)) { cout << -1 << endl; return 0; }

    for(ll j = 1, casa = 0; j <= u and casa < 63; j<<=1, casa++)
        if(u&j) ans[casa]++;

    ll sobra = (v-u);
    ll res = 0;

    for(ll j = 1, casa = 0; j <= sobra and casa < 63; j<<=1, casa++)
        if(sobra&j) ans[casa-1] += 2;

    for(ll i = 0,j=1; i < 63; i++, j<<=1) {
        res = max(res,ans[i]);
        for(int k = 1; k <= ans[i]; k++) vals[k]+=j;
    }

    cout << res << endl;
    for(int i = 1; i <= res; i++) cout << vals[i] << " ";
    cout << endl;


    return 0;
}

