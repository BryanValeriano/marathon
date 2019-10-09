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
const int T = 3e5 + 5;
int v[T];
ll n;
string s;
ll ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    ll ans = (n*(n-1) >> 1);

    for(int i = 1; i < n; i++) {
        tot++;
        if(s[i] != s[i-1]) e++;
        if(e == 2) {
            cout << i << " " << tot << endl;
            flag = 1;
            ans -= tot-1;
            tot = 1;
            e = 1;
        }
    }

    if(flag) ans -= max(0ll,tot-1);
    cout << ans << endl;

    return 0;
}


