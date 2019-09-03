#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 5;
const int N = 1e7 + 5;
string s,a;
int n,m;

int pi[T];
int nxt[T][30];
vector< vector<int> > dp;

void pre(string t) {
    pi[0] = pi[1] = 0;

    for(int i = 2; i <= t.size(); i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and t[pi[i]] != t[i-1]) pi[i] = pi[pi[i]];
        if(t[pi[i]] == t[i-1]) pi[i]++;
    }
}

void pre2() {
    nxt[0][a[0]-'a'] = 1;

    for(int i = 1; i < m; i++) {
        for(int j = 0; j < 26; j++) {
            char k = 'a' + j;
            if(k == a[i]) nxt[i][j] = i+1;
            else nxt[i][j] = nxt[pi[i]][j];
        }
    }
}



ll solve(int at, int x) {
    if(at == n) return 0;
    if(dp[at][x] != -1) return dp[at][x];
    
    ll ans = -INF;

    if(s[at] == '?') {
        for(int i = 0; i < 26; i++) {
            int xx = nxt[x][i];
            ans = max(ans, solve(at+1, xx) + (xx == (a.size()-1)));
        }
    } else {
        int xx = nxt[x][s[at]-'a'];
        ans = max(ans, solve(at+1, xx) + (xx == (a.size()-1)));
    }
    
    return dp[at][x] = ans; 
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> a;
    n = s.size();
	m = a.size() + 1;

    s += '#';
    a += '$';

	dp.resize(n+1);	

    for(int i = 0; i < n; i++) dp[i].resize(m+1,-1);
	
    pre(a);
    pre2();

    cout << solve(0, 0) << endl;

    return 0;
}
