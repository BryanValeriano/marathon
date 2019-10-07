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
const int T = 3e3 + 3;
int dp[T][T];
int choose[T][T];
int n,m;
string a,s,t;

int solve(int i, int j) {
    if(i == n or j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int a = 0, b = 0, c = 0;
    a = solve(i+1, j);
    b = solve(i,j+1);

    if(s[i] == t[j]) c = solve(i+1,j+1)+1;
    if(a >= b and a >= c) choose[i][j] = 0;
    else if(b >= c and b >= a) choose[i][j] = 1;
    else choose[i][j] = 2;
    return dp[i][j] = max({a,b,c});
}

void build(int i, int j) {
    if(i == n or j == m) return;
    if(choose[i][j] == 2) a += s[i], build(i+1,j+1);
    else if(choose[i][j] == 1) build(i,j+1);
    else build(i+1,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> s >> t;
    n = s.size(); m = t.size();
    solve(0,0);
    build(0,0);
    cout << a << endl;
    return 0;
}

