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
const int T = 2e5 + 4;
const int N = 21;

int n;
ll v[T];
ll acum[T][N];

bool noRep(int l, int r) {
    for(int i = 0; i < N; i++)
        if(acum[r][i]-acum[l-1][i] > 1) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        for(ll j = 1, casa = 0; j <= v[i]; j <<= 1, casa++)
            acum[i][casa] += ((v[i]&j) > 0);
        for(int j = 0; j < N; j++) acum[i][j] += acum[i-1][j];
    }

    int l = 1;
    int r = 1;
    ll ans = 0;

    while(r <= n) {
        while(l < r and (!noRep(l,r))) l++;
        while(r < n and noRep(l,r+1)) ans += (r-l+1), r++;
        ans += (r-l+1);
        r++;
    }

    cout << ans << endl;

    return 0;
}

