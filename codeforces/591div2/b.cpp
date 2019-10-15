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
int v[30];

bool solve() {
    memset(v, 0, sizeof v);
    for(int i = 0; i < s.size(); i++) v[s[i]-'a']++;
    for(int i = 0; i < t.size(); i++) if(v[t[i]-'a']) return 1;
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    while(q--) {
        cin >> s >> t;
        cout << (solve()? "YES" : "NO") << endl;
    }
    return 0;
}

