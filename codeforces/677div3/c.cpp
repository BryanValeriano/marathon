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
const int T = 3e5+5;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int maxi = 0;
        int ans = -1;
        v[0] = v[n+1] = 2e9;

        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            maxi = max(maxi,v[i]);
        }

        for(int i = 1; i <= n; i++)
            if(v[i] == maxi and (v[i] > v[i-1]  or v[i] > v[i+1])) ans = i;

        cout << ans << endl;
    }
    return 0;
}

