#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        int x,y; cin >> x >> y;
        string s; cin >> s;

        int ans = INF;
        if(x == y and x == 0) ans = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i]=='E') x++;
            else if(s[i]=='W')x--;
            else if(s[i]=='N')y++;
            else y--;
            if(abs(x)+abs(y) <= i+1) { ans = i+1; break; }
        }
        cout << "Case #" << ++cont << ": ";
        if(ans == INF) cout << "Impossible\n";
        else cout << ans << endl;
    }

    return 0;
}

