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
const int T = 303;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
        int l = 0, r = n-1;
        bool ok = 0;
        while(l <= r) {
            if(ok) cout << v[r--] << " ";
            else cout << v[l++] << " ";
            ok = !ok;
        }
        cout << endl;
    }
    return 0;
}

