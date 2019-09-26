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

int n; string s;
const int T = 5e3 + 5;
int pi[T];
int fdp = -3;

int pre() {
    string p = s;
    p += "#";
    int ans = 0;

    pi[0] = pi[1] = 0;
    for(int i = 2; i <= (int)p.size(); i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and p[pi[i]] != p[i-1]) pi[i] = pi[pi[i]];
        if(p[pi[i]] == p[i-1]) pi[i]++;
        if(pi[i] * 2 > i) ans = max(ans,pi[i] - max(0,(n-pi[i])));
        else ans = max(ans,pi[i]);
        if(n == fdp) {
            cout << i << " " << pi[i] << " " << pi[i] - max(0,(n-pi[i])) << endl;
        }
    }
    if(n == fdp) for(int i = 1; i < p.size(); i++) cout << pi[i] << " ";
    if(n == fdp) cout << endl;

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    int ans = 0;
    while(s.size()) {
        ans = max(ans, pre());
        string t;
        for(int i = 1; i < s.size(); i++) t += s[i];
        s = t;
        n--;
    }
    cout << ans << endl;
    return 0;
}

