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
const ll INF = 1e18;
const double PI = acos(-1.0);
const int T = 1e5 + 3;

vector<int> dvs;
int v[T];
int n;

ll tent(int sz) {
    vector<int> tmp;
    int m = sz/2;
    int mid;
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        if(v[i]) tmp.pb(i);
        if(tmp.size() == sz) {
            mid = tmp[m];
            for(int j = 0; j < sz; j++)
                ans += abs((ll)mid-(ll)tmp[j]);
            tmp.clear();
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int t = 0;

    for(int i = 1; i <= n; i++) cin >> v[i], t += v[i];

    for(int i = 2; i <= t; i++)
        if(!(t % i)) dvs.pb(i);

    ll ans = INF;
    for(auto x : dvs) ans = min(ans, tent(x));

    cout << (dvs.size()? ans : -1) << endl;
    return 0;
}

