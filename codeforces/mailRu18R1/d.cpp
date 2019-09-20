#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n,k;
map<int,ll> freq;

ll gauss(ll x) {
    return (x*(x-1))/2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    k = (1 << k) - 1;
    int p = 0;

    freq[0]++;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        p ^= min(x,x^k);
        freq[p]++;
    }

    ll x = 0;

    for(ii ok : freq) {
        x += gauss(ok.se/2);
        x += gauss(ok.se/2 + (ok.se&1));
    }

    cout << gauss(n+1) - x << endl;

    return 0;
}

