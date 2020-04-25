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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> s(n);
    vector<int> ans(n,0);
    vti b;

    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 0; i < m; i++) {
        int c; cin >> c;
        b.eb(0,c,i+1);
    }
    for(int i = 0; i < m; i++) {
        int r; cin >> r;
        get<0>(b[i]) = r;
    }

    sort(b.begin(), b.end());
    int ok = 0;

    for(int i = 0; i < m and ok < n; i++) {
        int best = -1;
        int id = 0;
        for(int j = 0; j < n; j++) {
            if(ans[j] or s[j] > get<1>(b[i])) continue;
            else if(best < s[j]) {
                best = s[j];
                id = j;
            }
        }
        if(~best) ans[id] = get<2>(b[i]), ok++;
    }

    if(ok == n) {
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
    } else cout << "impossible";
    cout << endl;

    return 0;
}

