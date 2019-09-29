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

void partiu() {
    cout << "NO" << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n,k,a,b;
    cin >> n >> k >> a >> b;
    while(n--) {
        ll x; cin >> x;
        if(x > k) partiu();
        ll c = k - x;
        ll d = min(b,c/2);
        b -= d;
        c -= d*2;
        ll u = min(a,c);
        a -= u;
        c -= u;
        if(c) partiu();
    }

    cout << "YES" << endl;

    return 0;
}

