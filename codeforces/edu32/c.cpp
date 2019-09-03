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

vector<int> v[30];
string s;

int main() {
    ios::sync_with_stdio(false);
    for(int i = 0; i < 30; i++) v[i].pb(0);

    cin >> s;

    for(int i = 0; i < s.size(); i++) 
        v[s[i]-'a'].pb(i+1);

    for(int i = 0; i < 30; i++) v[i].pb(s.size()+1);

    int ans = s.size();

    for(int i = 0; i < 30; i++) {
        int ok = (v[i].size() > 1? 0 : ans);
        for(int j = 1; j < v[i].size(); j++) {
            ok = max(ok, v[i][j] - v[i][j-1]); 
        }
        ans = min(ans,ok);
    }

    cout << ans << endl;

    return 0;
}

