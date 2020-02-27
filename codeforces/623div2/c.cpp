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

const int T = 102;
int a[T], b[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;

        vii need;
        set<int> disp;

        for(int i = 1; i <= 2*n; i++)
            disp.insert(i);

        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            disp.erase(b[i]);
            a[2*i-1] = b[i];
            need.eb(2*i,b[i]);
        }

        sort(need.begin(), need.end(), greater<ii>());
        bool f = 0;

        while(need.size()) {
            ii top = need.back();
            need.pop_back();
            int at = -1;

            for(auto x : disp) {
                //cout << top.se << " " << x << endl;
                if(x > top.se) { at = x; break; }
            }

            if(at == -1) { f = 1; break; }
            else {
                disp.erase(at);
                a[top.fi] = at;
            }
        }

        if(f) cout << -1 << endl;
        else {
            for(int i = 1; i <= 2*n; i++) cout << a[i] << " ";
            cout << endl;
        }

    }
    return 0;
}

