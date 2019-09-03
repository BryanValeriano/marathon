#include <bits/stdc++.h>
using namespace std;

const int T = 200;
bool vis[T];

int close(string x, string y) {
    int ans = 0;
    for(int i = 0; i < x.size(); i++)
        if(x[i] != y[i]) ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    string s[T];
    string t[T];
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s, s+n);
    sort(t, t+n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(t[i] == s[j] and !vis[j]) {
                vis[j] = true;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++) if(!vis[i]) ans++;
    
    cout << ans << endl;
    return 0;
}

