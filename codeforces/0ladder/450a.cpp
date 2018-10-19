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

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vii row;
    int aux;
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        row.eb(i,aux);
    }
    while(row.size() > 1) {
        row[0].se -= m;
        if(row[0].se > 0) {
            ii at = row[0];
            row.pb(at);
        }
        row.erase(row.begin());
    }
    cout << row[0].fi << endl;
        
    return 0;       
}

