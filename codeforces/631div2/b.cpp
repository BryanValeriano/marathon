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
const int T = 2e5+5;
ll v[T];
int freq[T];
int n;

bool ok(ll pos) {
    bool ans = 1;
    ans &= (pos*(pos+1)>>1) == v[pos];
    ll oPos = pos;
    pos = n-pos;
    ans &= (pos*(pos+1)>>1) == (v[n]-v[oPos]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) freq[i] = 0;
        int dup = 0, dup2 = 0;

        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            freq[v[i]]++;
            if(freq[v[i]]==2 and (!dup)) dup = i;
            v[i] += v[i-1];
        }

        for(int i = 1; i <= n; i++) freq[i] = 0;
        for(int i = n; i >= 1; i--) {
            ll x = v[i]-v[i-1];
            freq[x]++;
            if(freq[x]==2) {
                dup2 = i;
                break;
            }
        }

        vii ans;

        for(ll i = dup2; i < dup; i++)
            if(ok(i)) ans.eb(i, n-i);

        cout << ans.size() << endl;
        for(ii x : ans) cout << x.fi << " " << x.se << endl;
    }
    return 0;
}

