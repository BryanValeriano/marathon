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
vii segs;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a, b;
    int ini = INF;
    int fim = 0;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        ini = min(ini,a);
        fim = max(fim,b);
        segs.eb(a,b);
    }
    for(int i = 0; i < n; i++) 
        if(segs[i].fi == ini and segs[i].se == fim) {
            cout << i + 1 << endl;
            return 0;
        }
    cout << -1 << endl;
    return 0;
}
