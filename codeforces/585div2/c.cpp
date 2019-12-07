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
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s,t; cin >> s >> t;
    vector<int> ab,ba;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a' and t[i] == 'b') ab.pb(i+1);
        else if(s[i] == 'b' and t[i] == 'a') ba.pb(i+1);
    }

    int x = ((int)ab.size())&1;
    int y = ((int)ba.size())&1;

    if(x != y) cout << -1 << endl;
    else {
        bool ini = 0;
        int ans = (ab.size() + ba.size()) >> 1;
        if(x&1 and y&1) { ans++; ini = 1; }
        cout << ans << endl;
        if(ini) {
            cout << ab.back() << " " << ab.back() << endl;
            ba.pb(ab.back());
            ab.pop_back();
        }
        for(int i = 0; i < ab.size(); i += 2) cout << ab[i] << " " << ab[i+1] << endl;
        for(int i = 0; i < ba.size(); i += 2) cout << ba[i] << " " << ba[i+1] << endl;
    }
    
    return 0;
}

