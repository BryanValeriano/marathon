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

const int T = 3e5 + 3;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v,v+n);

    int r = n-1;
    int l = 0;
    ll ans = 0;

    while(l < r) ans += (v[l] + v[r]) * (v[l] + v[r]), l++, r--;

    cout << ans << endl;

    return 0;
}

