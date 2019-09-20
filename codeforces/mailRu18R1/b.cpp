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


int main() {
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    ll ok = 0;
    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if(x > ok) { cout << i << endl; return 0; }
        if(x == ok) ok++;
    }
    cout << -1 << endl;
    return 0;
}

