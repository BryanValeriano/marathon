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
const double PI = acos(-1.0);
const int T = 1e5+2;
const int N = 4;
int dp[T][N][N][N];
int choose[T][N][N][N];
int v[T][2];
int n;

int solve(int at, int a, int b, int c) {
    if((a<0) or (b<0) or (c<0)) return 0;
    if(at == n) return 1;
    a = min(a,3); b = min(b,3); c = min(c,3);
    int &r = dp[at][a][b][c];
    if(~r) return r;

    bool x = solve(at+1,a-(v[at][0]==0)+(v[at][1]==0),
            b-(v[at][0]==1)+(v[at][1]==1),
            c-(v[at][0]==2)+(v[at][1]==2));
    bool y = solve(at+1,a+(v[at][0]==0)-(v[at][1]==0),
            b+(v[at][0]==1)-(v[at][1]==1),
            c+(v[at][0]==2)-(v[at][1]==2));

    choose[at][a][b][c] = (x?1:0);

    return r = (x|y);
}

void build(int at, int a, int b, int c) {
    if(at==n) return;
    a = min(a,3);
    b = min(b,3);
    c = min(c,3);
    cout << (char)('A' + v[at][choose[at][a][b][c]]) << endl;
    if(!choose[at][a][b][c]) {;
        build(at+1,a+(v[at][0]==0)-(v[at][1]==0),
            b+(v[at][0]==1)-(v[at][1]==1),
            c+(v[at][0]==2)-(v[at][1]==2));
    } else {
        build(at+1,a-(v[at][0]==0)+(v[at][1]==0),
            b-(v[at][0]==1)+(v[at][1]==1),
            c-(v[at][0]==2)+(v[at][1]==2));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin.tie(0); cout.tie(0);
    int a,b,c;
    cin >> n >> a >> b >> c;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        v[i][0] = s[0]-'A', v[i][1] = s[1]-'A';
    }
    if(solve(0,a,b,c)) cout << "Yes" << endl, build(0,a,b,c);
    else cout << "No" << endl;
    return 0;
}
