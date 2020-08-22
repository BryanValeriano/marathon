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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        vector<int> z,o;
        vector<int> r;

        for(int i = 0; i < n; i++) {
            int x = s[i]-'0';

            if(x) {
                if(z.size()) {
                    r.pb(z.back());
                    o.pb(z.back());
                    z.pop_back();
                } else {
                    ans++;
                    o.pb(ans);
                    r.pb(ans);
                }
            } else {
                if(o.size()) {
                    r.pb(o.back());
                    z.pb(o.back());
                    o.pop_back();
                } else {
                    ans++;
                    z.pb(ans);
                    r.pb(ans);
                }
            }
        }

        cout << ans << endl;
        for(int x : r) cout << x << " ";
        cout << endl;

    }
    return 0;
}

