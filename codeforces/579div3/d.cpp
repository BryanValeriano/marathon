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
const int T = 2e5 + 5;

string s,t;
int ap[T][2];

void build(int ini, int pass) {
    int point = (ini? 0 : t.size()-1);

    for(int i = (ini? 0 : s.size()-1); i != (ini? s.size() : -1); i += pass) {
        if(point == t.size() or point == -1) break;
        if(t[point] == s[i]) ap[point][!ini] = i, point += pass;
    }

}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    memset(ap,-1, sizeof ap);
    build(1,1);
    build(0,-1);

    int ans = max(ap[0][1], (int)s.size() - ap[t.size()-1][0] - 1);
    for(int i = 1; i < t.size(); i++) ans = max(ans, ap[i][1]-ap[i-1][0]-1);
    cout << ans << endl; 
    
    return 0;
}

