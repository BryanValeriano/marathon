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

vector<ii> v;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a,b;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.eb(a,1);
        v.eb(b+1,-1);
    }
    
    sort(v.begin(), v.end());
    bool ok = 1;
    int x = 0;

    for(int i = 0; i < v.size(); i++) {
        x += v[i].se;
        ok &= (x <= 2);
    }

    cout << (ok? "YES" : "NO") << endl;
    return 0;
}

