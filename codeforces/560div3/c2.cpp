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
    string s; cin >> s;
    string ans;

    bool f = 0;
    char last;

    for(int i = 0; i < s.size(); i++) {
        if(f and s[i] == last) continue;

        if(f and s[i] != last) f = !f, ans += s[i]; 
        else if(!f) last = s[i], f = !f, ans += s[i];
    }

    if(ans.size()&1) ans.pop_back();

    cout << s.size()-ans.size() << endl;
    cout << ans << endl;
    
    
    return 0;
}

