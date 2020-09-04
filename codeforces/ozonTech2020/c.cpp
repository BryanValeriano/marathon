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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+5;
const int N = 2e5+5;
ll freq[T];
ll pre[T][T];
ll pre2[T][T];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    if(n > m) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++) {
            pre[i][j] = (i-j+m)%m;
            pre2[i][j] = (i*j)%m;
        }

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(),v.end(),greater<int>());
    ll ans = 1;

    for(int k = 0; k < n; k++) {
        int x = v[k]%m;
        for(int i = 0; i < m; i++) {
            if(!freq[i]) continue;
            ans = pre2[pre2[ans][pre[i][x]]][freq[i]];
        }
        freq[x]++;
    }

    cout << ans << endl;
    return 0;
}

