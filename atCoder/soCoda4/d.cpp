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
const int T = 10;

set<ii> points;
set<ii> sqrs;
ll h,w,n;
ll ans[T];

bool isIn(int i, int j) {
    return (i >= 1 and j >= 1 and i+2 <= h and j+2 <= w);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> h >> w >> n;

    ans[0] = (h-2) * (w-2);

    while(n--) {
        int x,y; cin >> x >> y;
        points.emplace(x,y);
        for(int i = x-2; i <= x; i++)
            for(int j = y-2; j <= y; j++)
                if(isIn(i,j)) sqrs.emplace(i,j);
    }

    for(ii x : sqrs) {
        int qtd = 0;
        for(int i = x.fi; i <= x.fi+2; i++)
            for(int j = x.se; j <= x.se+2; j++)
                if(points.count(mk(i,j))) qtd++;
        if(qtd) ans[0]--, ans[qtd]++;
    }

    for(int i = 0; i < T; i++) cout << ans[i] << endl;

    return 0;
}

