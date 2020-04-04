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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        int n; cin >>n;
        vti v;

        for(int i = 0; i < n; i++) {
            int x,y; cin >> x >> y;
            v.eb(x,y,i);
        }

        sort(v.begin(),v.end());

        int c = 0, j = 0;
        char ans[n];
        string imp;

        for(ti atv : v) {
            int ini,fim,id;
            tie(ini,fim,id) = atv;
            if(ini >= c) ans[id] = 'C', c = fim;
            else if(ini >= j) ans[id] = 'J', j = fim;
            else { imp = "IMPOSSIBLE"; break; }
        }

        if(!imp.size())
            for(int i = 0; i < n; i++) imp += ans[i];

        cout << "Case #" << ++cont << ": " << imp << endl;
    }
    return 0;
}

