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

vii r;

int main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin >> n >> a >> b;
    for(int i = 0; i < a; i++) {
        int x,y; cin>>x>>y;
        r.eb(x,y);
    }

    double best = 0;

    for(int i = 0; i < b; i++) {
        int x,y; cin >> x >> y;
        for(int j = 0; j < a; j++) {
            int xx,yy;
            tie(xx,yy) = r[j];
            best = max(best,hypot(abs(x-xx)*abs(x-xx),abs(y-yy)*abs(y-yy)));
        }
    }

    cout << fixed << setprecision(6) << best << endl;




    return 0;
}

