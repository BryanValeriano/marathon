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
        string s; cin >> s;
        string ans;
        int o = 0;
        for(int i = 0; i < s.size(); i++) {
            while(o < s[i]-'0') ans += "(", o++;
            while(o > s[i]-'0') ans += ")", o--;
            ans += s[i];
        }
        while(o) ans += ")", o--;
        cout << "Case #" << ++cont << ": " << ans << endl;
    }

    return 0;
}

