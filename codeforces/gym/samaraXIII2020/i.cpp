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
const int T = 2e5 + 3;
vector<int> v[T];

bool isOk(int x) {
    bool ok = 1;
    for(int i = 1; i < v[x].size() and x; i++) ok &= v[x][i] >= v[x][i-1];
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    while(n--) {
        int x,y; cin >> x >> y;
        v[y].pb(x);
    }

    bool ans = 1;
    for(int i = 0; i < T and ans; i++) ans &= isOk(i);
    cout << (ans? "YES": "NO") << endl;

    return 0;
}

