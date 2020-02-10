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
    while(tc--) {
        string s; cin >> s;
        int u = 0,d = 0,l = 0,r = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'U') u++;
            else if(s[i] == 'D') d++;
            else if(s[i] == 'L') l++;
            else r++;
        }

        if(u and d and l and r) {
            d = min(d,u);
            u = d;
            l = min(l,r);
            r = l;
            cout << (d+u+l+r) << endl;
            while(d--) cout << 'D';
            while(l--) cout << 'L';
            while(u--) cout << 'U';
            while(r--) cout << 'R';
            cout << endl;
        } else {
            if(u and d) cout << 2 << endl << "UD" << endl;
            else if(l and r) cout << 2 << endl << "LR" << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}

