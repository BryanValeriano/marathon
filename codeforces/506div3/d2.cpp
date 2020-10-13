#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5+5;
const int N = 10;

int v[T];
unordered_map<int,int> rest[N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        int ok = (int)log10(v[i]);
        rest[ok][v[i]%k]++;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        int x = v[i];
        int ok = (int)log10(v[i]);
        int tmp = 0, need = 0;
        for(int j = 0; j < N; j++) {
            x = (x*10ll)%k;
            need = (k-x);
            if(need==k) need = 0;
            if(rest[j].count(need))
                ans += (ll)rest[j][need];
            if(j==ok) tmp = need;
        }
        if(v[i]%k == tmp) ans--;
    }

    cout << ans << endl;
    return 0;
}

