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

const int T = 1e5 + 3;
int resource[T];
vector<ii> v;
vector<int> ans;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    int x;
    int gol;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> resource[i];
        v.eb(x,i);
        if(i == n-1) gol = x;
    }

    sort(v.begin(), v.end());

    int at = 0;
    int m = 1;

    if(gol <= 1) { cout << 1 << endl << n << endl; return 0; }

    while(at < n) {
        int idp = 0;
        int best = 0;

        while(at < n and v[at].fi <= m) {
            if(resource[v[at].se] > best) {
                best = resource[v[at].se];
                idp = v[at].se + 1;
            }
            at++;
        }

        if(best <= m) {
            cout << "No such luck" << endl;
            return 0;
        }

        m = best;
        ans.pb(idp);
        if(m >= gol) { ans.eb(n); break; }
    }

    cout << ans.size() << endl;
    for(auto ok : ans) cout << ok << " ";
    cout << endl;

    return 0;
}

