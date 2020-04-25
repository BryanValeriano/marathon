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
int gol;
map<int,int>id;
map<int,int>pk;

int brute(auto x, int lim) {
    if(x == id.end()) return true;
    for(auto y : pk) {
        if(y.se >= x->se and y.fi > lim) {
             return brute(++x, y.fi);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n, m, aux;
        cin >> n >> m;
        id.clear();
        pk.clear();
        for(int i = 0; i < n; i++) {
            cin >> aux;
            id[aux]++;
        }
        for(int i = 0; i < m; i++) {
            cin >> aux;
            pk[aux]++;
        }
        gol = id.size();
        map<int,int>::iterator x = id.begin();
        cout << (brute(x, 0)? "YES" : "NO") << endl;
    }
    return 0;
}

