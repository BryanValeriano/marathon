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

int main() {
    ios::sync_with_stdio(false);
    int q; cin >> q;

    while(q--) {
        ll n,s,t;
        cin >> n >> s >> t;
        ll two = max(0LL, (s+t - n));
        cout << max(s-two, t-two) + 1 << endl;
    }

    return 0;
}

