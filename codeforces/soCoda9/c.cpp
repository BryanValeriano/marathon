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
typedef tuple<int,int,int> ti;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 4;

map<ti,int> dp;
map<ti,int> last;

int r[4];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    last[make_tuple(0,0,0)] = 0;

    while(n--) {
        int x; cin >> x;

        for(auto z : last) {
            tie(r[0],r[1],r[2]) = z.fi;

            int tmp = (dp.count(make_tuple(r[0],r[1],r[2]))?
                    dp[make_tuple(r[0],r[1],r[2])] : INF);

            dp[z.fi] = min(tmp,z.se+1);

            for(int j = 0; j < 3; j++) {
                if(r[j] and j+1 + x <= 4) {
                    r[j]--;
                    r[j+x]++;

                    tmp = (dp.count(make_tuple(r[0],r[1],r[2]))?
                            dp[make_tuple(r[0],r[1],r[2])] : INF);

                    dp[make_tuple(r[0],r[1],r[2])] = min(z.se,tmp);

                    r[j+x]--;
                    r[j]++;
                }

                if(j+1 + x == 4) {
                    r[x-1]++;

                    tmp = (dp.count(make_tuple(r[0],r[1],r[2]))?
                            dp[make_tuple(r[0],r[1],r[2])] : INF);

                    dp[make_tuple(r[0],r[1],r[2])] = min(z.se+1,tmp);

                    r[x-1]--;
                }
            }
        }

        last = dp;
        dp.clear();
    }

    int ans = INF;
    for(auto x : last) ans = min(ans,x.se);
    cout << ans << endl;
    return 0;
}

