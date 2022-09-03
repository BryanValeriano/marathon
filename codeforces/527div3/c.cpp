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
const int T = 500;
vector<pair<string, int>> v[T];
char ans[T];
int n;

bool checkPref(int sizeLast, int last, int sizeAt, int at) {
    for(int i = 0; i < sizeLast; i++)  {
        if(v[sizeLast][last].fi[i] != v[sizeAt][at].fi[i]) return false;
        if(v[sizeLast][!last].fi[sizeLast-i-1] != v[sizeAt][!at].fi[sizeAt-i-1]) return false;
    }
    return true;
}

bool solve(int size, bool last) {
    if(size == n) return true;

    bool ok = false;

    for(int i = 0; i <= 1 && !ok; i++) {
        if(checkPref(size-1, last, size, i)) {
            ok |= solve(size+1,i);
            if(ok) {
                ans[v[size][i].se] = 'P';
                ans[v[size][!i].se] = 'S';
            }
        }
    }

    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < 2*n-2; i++) {
        string s; cin >> s;
        v[s.size()].eb(s,i);
    }
    
    solve(1,0);
    for(int i = 0; i < 2*n-2; i++) cout << ans[i];
    cout << endl;

    return 0;
}

