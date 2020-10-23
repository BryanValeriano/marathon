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
const int T = 2e5+5;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,k; cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> v[i];
        if(n == 1 or k == 0) {
            cout << 0 << endl;
            continue;
        }
        sort(v,v+n);
        for(int i = n-2; i >= 0 and k; i--, k--) {
            //cout << v[n-1] << endl;
            v[n-1] += v[i];
        }
        cout << v[n-1] << endl;
    }
    return 0;
}

