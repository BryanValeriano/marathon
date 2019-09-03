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

const int T = 1e5 + 5;
int x[T];
int y[T];
int z[T];

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;

    x[0] += (s[0] == 'x');
    y[0] += (s[0] == 'y');
    z[0] += (s[0] == 'z');

    for(int i = 1; i < s.size(); i++) {
        x[i] += (s[i] == 'x') + x[i-1];
        y[i] += (s[i] == 'y') + y[i-1];
        z[i] += (s[i] == 'z') + z[i-1];
    }

    int q; cin >> q;
    
    while(q--) {
        int l,r; cin >> l >> r;
        l--; r--;
        if(r-l+1 < 3) { cout << "YES" << endl; continue; }

        int xx = x[r] - (l > 0? x[l-1] : 0);
        int yy = y[r] - (l > 0? y[l-1] : 0);
        int zz = z[r] - (l > 0? z[l-1] : 0);

        if(abs(xx-yy) < 2 and abs(xx-zz) < 2 and abs(yy-zz) < 2)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

