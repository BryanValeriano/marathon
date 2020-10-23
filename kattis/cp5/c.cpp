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
const int T = 1e3+2;
int v[2][T];
set<vii> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int w,l,n;
    cin >> w >> l >> n;
    while(n--) {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < l; j++) cin >> v[i][j];

        vii tmp;
        vii tmp2;
        vii tmp3;
        vii tmp4;

        for(int i = 0; i < l; i++) {
            if(i==0) {
                tmp.eb(w-(v[0][i]+v[1][i]), 0);
                tmp2.eb(w-(v[0][i]+v[1][i]), 0);
            } else {
                tmp.eb(v[0][i-1]-v[0][i], v[1][i-1]-v[1][i]);
                tmp2.eb(v[1][i-1]-v[1][i],v[0][i-1]-v[0][i]);
            }
        }

        for(int i = l-1; i >= 0; i--) {
            if(i==l-1) {
                tmp3.eb(w-(v[0][i]+v[1][i]), 0);
                tmp4.eb(w-(v[0][i]+v[1][i]), 0);
            } else {
                tmp3.eb(v[0][i+1]-v[0][i], v[1][i+1]-v[1][i]);
                tmp4.eb(v[1][i+1]-v[1][i],v[0][i+1]-v[0][i]);
            }
        }

        if(bag.count(tmp)) bag.insert(tmp);
        else if(bag.count(tmp2)) bag.insert(tmp2);
        else if(bag.count(tmp3)) bag.insert(tmp3);
        else bag.insert(tmp4);
    }

    cout << bag.size() << endl;
    return 0;
}

