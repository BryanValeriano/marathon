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

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b; cin >> a >> b;
    double x = 0.08;
    double y = 0.1;
    ll ok = 0;
    for(ok = 0; ok < 1e6; ok++)
        if((ll)(ok*x) == a and (ll)(ok*y) == b)break;
    cout << ((ll)(ok*x) == a and (ll)(ok*y) == b? ok : -1) << endl;
    return 0;
}

