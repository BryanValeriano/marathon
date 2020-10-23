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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        bool ans = 0;
        for(int i = 0; 3*i <= n and !ans; i++) {
            for(int j = 0; j < 3 and !ans; j++) {
                for(int k = 0; k < 3 and !ans; k++) {
                    int s = (3*i+5*j+7*k);
                    if(s == n) {
                        cout << i << " " << j << " " << k << endl;
                        ans = 1;
                    }
                }
            }
        }
        if(!ans) cout << -1 << endl;
    }
    return 0;
}

