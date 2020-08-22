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
const int T = 5e5+5;
int n,c,b;
bool s[T];
bool lk[T];
int dp[T][3], choose[T][3];

int solve(int at, int last) {
    if(at == n-1) return (last != 0);

    int &r = dp[at][last];
    if(~r) return r;

    r = solve(at+1,0) + (last != 0);
    choose[at][last] = 0;

    if(!lk[at]) {
        int ans2 = solve(at+1,1) + (last != 1);
        if(ans2 > r) {
            r = ans2;
            choose[at][last] = 1;
        }
    }

    return r;
}

void build(int at, int last) {
    if(at == n-1) return;
    s[at] = choose[at][last];
    build(at+1, choose[at][last]);
}

int tiraDois(int ans, int c) {
    for(int i = 1; i < n-1; i++) {
        if(lk[i]) continue;
        if(ans-2 >= c and s[i] == 1 and s[i-1] == 0 and s[i+1] == 0) {
            s[i] = 0;
            ans -= 2;
        }
    }

    return ans;
}

void tiraUm() {
    if(s[0] == 1) s[0] = 0;
    else {
        for(int i = 1; i < n-1; i++) {
            if(lk[i]) continue;
            if(s[i] == 1 and s[i-1] == 0 and s[i+1] == 0) {
                s[i] = 0;
                break;
            }
        }
        s[0] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> c >> b;

    for(int i = 0; i < b; i++) {
        int x; cin >> x;
        x--;
        lk[x] = 1;
    }

    int ans = solve(0,2)-1;
    build(0,2);
    ans = tiraDois(ans,c);
    if(ans != c) tiraUm();
    for(int i = 0; i < n; i++) cout << s[i];
    cout << endl;

    return 0;
}

