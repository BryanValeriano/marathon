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

const int T = 30;
int v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        string s; cin >> s;
        memset(v,0, sizeof v);
        char last = s[0];
        set<char> ans;
        v[last-'a']++;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == last) v[last-'a']++;
            else {
                if(v[last-'a']&1) ans.insert(last);
                v[last-'a'] = 0;
                last = s[i];
                v[last-'a'] = 1;
            }
        }
        if(v[last-'a']&1) ans.insert(last);
        v[last-'a'] = 0;
        for(auto x : ans) cout << x;
        cout << endl;
    }

    return 0;
}

