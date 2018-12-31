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
set<ii> resp;
set<ii> resp1;
set<ii> resp2;
ii a, b, c;

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isIn(ii x) {
    return (x.fi >= 0 and x.se >= 0);
}

void way(ii x, ii y, int t) {
    double dist = hypot((x.fi - y.fi) , (x.se - y.se));

    while(x.fi != y.fi or x.se != y.se) {
        for(int i = 0; i < 4; i++) {
            ii xx = ii(x.fi + mov[i][0], x.se + mov[i][1]);
            double ndist = hypot((xx.fi - y.fi) , abs(xx.se - y.se));

            if(isIn(xx) and ndist < dist) {
                if(t == 0) resp.insert(xx); 
                else if(t == 1) resp1.insert(xx);
                else resp2.insert(xx);
                x = xx;
                dist = ndist;
            }
        }
    }
}

void print(ii ans) {
    if(ans == a) {
        resp.insert(a);
        way(a,b,0);
        way(a,c,0);
    }
    else if(ans == b) {
        resp1.insert(b);
        way(b,a,1);
        way(b,c,1);
    } else {
        resp2.insert(c);
        way(c,a,2);
        way(c,b,2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a.fi >> a.se;
    cin >> b.fi >> b.se;
    cin >> c.fi >> c.se;

    print(a);
    print(b);
    print(c);

    if(resp.size() <= resp1.size() and resp.size() <= resp2.size()) {
        cout << resp.size() << endl;
        for(auto x : resp) cout << x.fi << " " << x.se << endl;
    }
    else if(resp1.size() <= resp.size() and resp1.size() <= resp2.size()) {
        cout << resp1.size() << endl;
        for(auto x : resp1) cout << x.fi << " " << x.se << endl;
    } else {
        cout << resp2.size() << endl;
        for(auto x : resp2) cout << x.fi << " " << x.se << endl;
    }


    return 0;
}

