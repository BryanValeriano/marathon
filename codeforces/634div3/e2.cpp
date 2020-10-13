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
const int T = 2e5+2;
const int N = 202;
int freq[T][N];
vector<int> pos[N];

int best(int l, int r) {
    int ans = 0;
    for(int i = 1; i < N; i++)
        ans = max(ans, freq[r-1][i]-freq[l][i]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i < N; i++) pos[i].clear();

        for(int i = 1; i <= n; i++) {
            memset(freq[i],0,sizeof freq[i]);
            int x; cin >> x;
            freq[i][x]++;
            pos[x].pb(i);
            for(int j = 1; j < N; j++)
                freq[i][j] += freq[i-1][j];
        }

        int ans = 1;

        for(int i = 1; i < N; i++) {
            int l = 0;
            int r = pos[i].size()-1;
            while(l < r) {
                ans = max(ans,(l+1)*2+best(pos[i][l],pos[i][r]));
                l++;
                r--;
            }
        }

        cout << ans << endl;

    }
    return 0;
}

