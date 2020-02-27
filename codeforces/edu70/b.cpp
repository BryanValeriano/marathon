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
const int INF = 0x3f3f3f3f;
const int T = 10;

int dp[T][T][T][T][3*T][2];

int solve(int x, int y, int ori, int gol, int corn, int qtd) {
    if(qtd > 25) return INF;
    if(ori == gol and !corn) return 0;
    int &r = dp[x][y][ori][gol][qtd][corn];
    if(r != -1) return r;
    r = min(solve(x,y,(ori+x)%10,gol,0,qtd+1)+1,solve(x,y,(ori+y)%10,gol,0,qtd+1)+1);
    return r;
}

ll calc(int x, int y, string &s) {
    ll ans = 0;

    for(int i = 1; i < s.size(); i++) {
        int tmp = solve(x,y,s[i-1]-'0',s[i]-'0', (s[i-1] == s[i]), 0);
        if(tmp >= INF) return -1;
        ans += max(0ll,(ll)tmp-1);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    string s; cin >> s;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++)
            cout << calc(min(i,j),max(i,j),s) << " ";
        cout << endl;
    }

    //cout << solve(1,7,0,8,0,0) << endl;
    //cout << solve(1,7,8,8,1,0) << endl;

    return 0;
}

