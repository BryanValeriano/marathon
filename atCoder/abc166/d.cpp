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
const int T = 1000;

ll calc(ll a, ll b) {
    ll bb = b;
    ll aa = a;
    for(int i = 1; i < 5; i++) bb *= b, aa *= a;
    return aa-bb;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll x; cin >> x;
    for(ll i = -T; i <= T; i++)
        for(ll j = -T; j <= T; j++) {
            if(calc(i,j)==x) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    return 0;
}

