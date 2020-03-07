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

string s,t;

int id(char x) {
    for(int i = 0; i < t.size(); i++)
        if(x == t[i]) return i;
    return 0;
}

int tent() {
    int dp[3] = {0,0,0};
    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        int x = id(s[i]);
        int maxi = 0;
        for(int j = 0; j <= x; j++) maxi = max(maxi,dp[j]);
        if(maxi+1 > dp[x]) dp[x] = maxi+1;
        ans = max(ans,dp[x]);
    }
    
    //cout << t << " " << " " << s << " " << ans << endl;
    return ((int)s.size() - ans);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string ss;
    cin >> ss;
    t = "ABC";
    int k = ss.size()-1;

    while(k > 0 and ss[k] == ss[0]) k--;
    for(int i = k+1; i < ss.size(); i++) s += ss[i];
    for(int i = 0; i <= k; i++) s += ss[i];
    
    int ans = INF;

    do {
        ans = min(ans,tent());
    } while(next_permutation(t.begin(), t.end()));

    cout << (ans == 1? 2 : ans) << endl; 
    
    return 0;
}

