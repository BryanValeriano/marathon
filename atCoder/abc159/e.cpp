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
const int N = 11;
const int T = 1e3+2;
int v[N][T];
int tmp[N];
int h,w,k;

int solve(int mask) {
    memset(tmp,0,sizeof tmp);
    int ans = 0;

    for(int j = 1; j <= w; j++) {
        int at = 0;

        for(int i = 1; i <= h; i++) {
            int s = i-1;
            tmp[at] += v[i][j];
            if((1<<s)&(mask)) at++;
        }

        bool ok = 0;
        for(int p = 0; p <= at; p++) {
            if(tmp[p] > k) ok = 1;
        }

        if(ok) {
            at = 0;
            memset(tmp,0,sizeof tmp);
            for(int i = 1; i <= h; i++) {
                int s = i-1;
                tmp[at] += v[i][j];
                if(tmp[at] > k) return INF;
                if((1<<s)&(mask)) at++;
            }
            ans++;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> h >> w >> k;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            char c; cin >> c;
            v[i][j] = (c=='1');
        }
    }

    int gol = (1<<(h));
    int ans = INF;

    for(int mask = 0; mask < gol; mask++) {
        ans = min(ans, solve(mask)+ __builtin_popcount(mask));
    }

    cout << ans << endl;
    return 0;
}

