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

ll cdiv(ll x, ll y) {
    return x / y + (x%y>0);
}

ll qtd(ll a, ll b) {
    return cdiv(a,2) * cdiv(b,2) + (a/2) * (b/2);
}

ll W(ll x1, ll y1, ll x2, ll y2) {
    return qtd(x2,y2) - qtd(x1-1, y2) - qtd(x2, y1-1) + qtd(x1-1, y1-1);
}

ll B(ll x1, ll y1, ll x2, ll y2) {
    return (x2-x1+1) * (y2-y1+1) - W(x1, y1, x2, y2);
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll X, Y, X1, Y1, X2, Y2, X3, Y3, X4, Y4;
        cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;
        ll white = W(1,1,X,Y); 
        ll black = B(1,1,X,Y);

        ll tiraB = B(X1,Y1,X2,Y2);
        white += tiraB;
        black -= tiraB;

        ll tiraW = W(X3,Y3,X4,Y4);
        white -= tiraW;
        black += tiraW;


        if(max(X1,X3) <= min(X2,X4) and max(Y1,Y3) <= min(Y2,Y4)) {
            ll inter = B(max(X1,X3), max(Y1,Y3), min(X2,X4), min(Y2,Y4));;
            white -= inter;
            black += inter;
        }
        cout << white << " " << black << endl;
    }
        

    return 0;
}

