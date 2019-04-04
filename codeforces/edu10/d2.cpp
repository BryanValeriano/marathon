#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define eb emplace_back

typedef long long ll;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

struct ii { 
    int fi, se;

    bool operator < (ii b) const {
        if(fi != b.fi) return fi < b.fi;
        return se < b.se;
    }
};

vector<ii> v;
vector<ii> ord;
map<ii,int> busc;


int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int x,y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.pb({x,y});
        ord.pb({x,y});
    }

    sort(ord.begin(), ord.end());
    for(int i = 0; i < n; i++) {
        ii tmp = ii({ord[i].se, ord[i].se});
        int low = lower_bound(ord.begin(), ord.end(), tmp) - ord.begin(); 

        if(low >= n) low--;
        while(low >= 0 and ord[low].se > ord[i].se) low--;

        busc[ord[i]] = max(0, low-i);
        cout << i << " " << low << endl;
    }
    for(int i = 0; i < n; i++) cout << busc[v[i]] << endl;

    return 0;
}

