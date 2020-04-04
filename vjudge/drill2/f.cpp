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
const int T = 8;
int c[T];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < T; i++) cin >> c[i];
    int p; cin >> p;

    while(p--) {
        int x,y; cin >> x >> y;
        x--,y--;
        v.eb((1<<x)|(1<<y));
    }

    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    int ans = 0;

    for(int i = 0; i < 256; i++) {
        bool f = 0;
        for(int j = 0; j < v.size(); j++)
            if((i|v[j]) == i) { f = 1; break; }
        if(!f) {
            int x = 0;
            for(int j = 0; j < 8; j++) if(i & (1<<j)) x += c[j];
            ans = max(ans,x);
        }
    }

    cout << ans << endl;
    return 0;
}

