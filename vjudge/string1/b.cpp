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

const int T = 1e6 + 5;
string s;
int z[T];

bool ok(int x) {
    string t;
    int n = s.size();
    for(int i = 0; i < x; i++) t += s[i]; 
    for(int i = 0; i < n; i++) if(s[i] != t[i%x]) return 0;
    return 1;
}

void solve() {
    int n = s.size();
    int ans = 1;
    //for(int i = 0; i < n; i++) cout << z[i] << " ";
    //cout << endl;
    for(int i = n-1; i >= 0; i--) {
        if(!z[i] or i+z[i] != n) continue;
        int j = i;
        while(j - z[i] >= 0 and z[j-z[i]] == z[j]+z[i]) j -= z[i];
        if(j == z[i]) ans = max(ans,n/z[i]);
    }
    cout << ans << endl;
}

void ze() {
    int l = 0, r = 0;
    int n = s.size();
    for(int i = 0; i <= n; i++) z[i] = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(z[i-l], r-i+1);
        while(z[i] + i < n and s[z[i]+i] == s[z[i]]) z[i]++;
        if(r < i + z[i] - 1) l = i, r = i + z[i]-1;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    while(s != ".") {
        ze();
        solve();
        cin >> s;
    }
    return 0;
}

