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

map<int,ll> v1;
map<int,ll> v2;

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v1[x]++;
        v2[x] += v1[x-1];
        ans += v2[x-k];
    }

    cout << ans << endl cout << ans << endl;;

    return 0;
}

