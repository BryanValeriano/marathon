#include <bits/stdc++.h>
using namespace std;

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
const int T = 1e5+5;
int point[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll n,l,r; cin >> n >> l >> r;
        ll ini = 1;
        ll step = n-1;
        ll prob = 0;

        while(ini+step+step-(ini==1?1:0) <= l and step) {
            ini += step+step-(ini==1?1:0);
            step--;
            prob++;
        }

        for(int i = prob; i <= n; i++)
            point[i] = (i==prob+1?i+1:prob+1);

        int at = (ini==1? 1 : n);
        point[n] = (point[n]==1?2:point[n]);
        point[n] = (point[n]==n?1:point[n]);
        //cerr << ini << " | ";
        //cerr << l << " = ";

        while(ini <= r) {
            if(ini >= l) cout << (at<=n?at:1) << " ";
            int nxt = point[at];
            point[at]++;
            if(point[at]==at) point[at]++;
            ini++;
            at = nxt;
        }

        cout << endl;
    }
    return 0;
}

