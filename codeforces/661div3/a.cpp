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
const int T = 100;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v,v+n);
        bool ok = 1;
        for(int i = 1; i < n; i++) ok &= (v[i]-1 <= v[i-1]);
        cout << (ok? "YES" : "NO") << endl;
    }
    return 0;
}

