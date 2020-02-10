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
const int T = 1e5 + 5;

vector<ll> acum;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; ll s;
        cin >> n >> s;
        ll sum = 0;
        acum.clear();

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
            acum.pb(sum);
        }

        if(sum <= s) {
            cout << 0 << endl;
            continue;
        }

        int p = 1;
        int best = 0;

        for(int i = 0; i < n; i++) {
            if(i > 0 and acum[i-1] >= s) break;
            int pos = upper_bound(acum.begin(),acum.end(),s+v[i]) - acum.begin();
            if(pos > best) best = pos, p = i+1;
        }

        cout << p << endl;

    }
    return 0;
}

