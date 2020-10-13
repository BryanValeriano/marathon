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
        int n,a,b; cin >> n >> a >> b;
        char x = 'a';
        string ans;
        for(int i = 0; i < n; i++) {
            if(i < a) {
                ans += x;
                if(i+1 < b) x++;
            } else ans += ans[i-a];
        }
        cout << ans << endl;
    }
    return 0;
}

