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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        map<int,int> freq;
        ll ans = 0;

        while(n--) {
            int x; cin >> x;
            if(!(x&1)) freq[x]++;
        }

        while(freq.size()) {
            ans++;
            ii at = *freq.rbegin();
            freq.erase(at.fi);
            at.fi /= 2;
            if(!(at.fi&1)) freq[at.fi] += at.se;
        }

        cout << ans << endl;

    }
    return 0;
}

