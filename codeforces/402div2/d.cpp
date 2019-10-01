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
const int T = 2e5 + 4;

string s;
string p;
vector<int> v;
bool tira[T];


bool check(int x) {
    int c = 0;
    for(int i = 0; i < x; i++) tira[v[i]] = 1;
    for(int i = 0; i < s.size() and c < p.size(); i++) if(!tira[i] and s[i] == p[c]) c++;
    for(int i = 0; i < x; i++) tira[v[i]] = 0;
    return (c == p.size());
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> p;
    for(int i = 0; i < s.size(); i++) {
        int x; cin >> x; x--;
        v.pb(x);
    }

    int l = 0;
    int r = s.size();
    int ans = 0;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << endl;
    
    return 0;
}

