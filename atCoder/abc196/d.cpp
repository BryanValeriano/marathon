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
const int T = 20;
int h,w,a,b;
bool v[T][T];

ll solve(int lin, int col, int dois, int um) {
    if(!dois and !um) return 1;
    if(col == w) col=0, lin++;
    if(lin == h) return 0;
    if(v[lin][col]) return solve(lin,col+1,dois,um);

    ll ans = 0;
    for(int i = 0; i < 3; i++) {
        if(i == 0) {
            if(!um) continue;
            ans += solve(lin,col+1,dois,um-1);
        } else if(i == 1) {
            if((!dois) or col+1 == w or v[lin][col+1]) continue;
            ans += solve(lin,col+2,dois-1,um);
        } else if(i == 2) {
            if((!dois) or lin+1 == h) continue;
            v[lin+1][col] = 1;
            ans += solve(lin,col+1,dois-1,um);
            v[lin+1][col] = 0;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> h >> w >> a >> b;
    cout << solve(0,0,a,b) << endl;
    return 0;
}

