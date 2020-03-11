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
    string s; cin >> s;
    int q; cin >> q;
    bool rev = 0;
    int op,f;
    char x;
    string a[2];

    while(q--) {
        cin >> op;
        if(op == 1) rev = !rev;
        else {
            cin >> f >> x;
            if(f == 1) {
                if(rev) a[1].pb(x);
                else a[0].pb(x);
            } else {
                if(rev) a[0].pb(x);
                else a[1].pb(x);
            }
        }
    }
    reverse(a[0].begin(), a[0].end());
    s = a[0] + s + a[1];
    if(rev) reverse(s.begin(),s.end());
    cout << s << endl;

    return 0;
}

