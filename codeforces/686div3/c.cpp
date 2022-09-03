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
vector<int> freq[T];
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(freq[v[i]].size() == 0 and i != 0) freq[v[i]].pb(-INF);
            freq[v[i]].pb(i);
        }
        for(int i = 1; i <= n; i++) {
            if(!freq[i].size()) continue;
            if(freq[i].back() != n-1) freq[i].pb(INF);
        }

        int ans = INF;
        for(int i = 1; i <= n; i++) {
            if(!freq[i].size()) continue;
            int tmp = 0;
            for(int j = 1; j < freq[i].size(); j++)
                if(freq[i][j]-1 == freq[i][j-1]) tmp++;
            ans = min(ans,(int)freq[i].size()-tmp-1);
        }

        cout << ans << endl;

        for(int i = 0; i < n; i++) freq[v[i]].clear();
    }
    return 0;
}
