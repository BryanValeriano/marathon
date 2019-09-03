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

const int T = 1e5 + 2;
int dp[T][30];
int prob[30][30];
int n,k;
string s;

int solve(int at, int last) {
    if(at == n)return 0;
    if(prob[s[at]-'a'][last] == 1) return solve(at+1,last)+1;
    if(dp[at][last] != -1) return dp[at][last];

    int ans = min(solve(at+1, s[at]-'a'), solve(at+1, last) + 1); 


    return dp[at][last] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> s;
    n = s.size();
    cin >> k;

    char a,b;

    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        prob[a-'a'][b-'a'] = 1;
        prob[b-'a'][a-'a'] = 1;
    }

    cout << solve(0,29) << endl;

    return 0;
}

