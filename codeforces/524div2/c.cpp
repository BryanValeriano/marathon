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

ll X, Y, X1, Y1, X2, Y2, X3, Y3, X4, Y4;

pair<ll,ll> qtd(ll xx, ll yy) {
    ll branco = ((xx/2) + (xx&1? 1 : 0)) * yy;
    ll preto = ((xx/2) + (xx&1? 1 : 0)) * yy;
    if(xx&1) {
        branco -= yy/2;
        preto -= yy/2;
    }
    return mk(branco, preto);
}

void casta() {
    X1 = min(X1,X);
    X2 = min(X2,X);
    X3 = min(X3,X);
    X4 = min(X4,X);

    Y1 = min(Y1, Y);
    Y2 = min(Y2, Y);
    Y3 = min(Y3, Y);
    Y4 = min(Y4, Y);
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;
        casta();
        pair<ll,ll> tot = qtd(X,Y); 
        if(X == Y and X&1) tot.se--;

        pair<ll,ll> white = qtd(X2-X1+1, Y2-Y1+1);
        if(X2-X1 == Y2-Y1 and abs(X2-Y2)&1 and (X2-X1+1)&1) white.fi--;
        if(X2-X1 == Y2-Y1 and (! abs(X2-Y2)&1) and (X2-X1+1)&1) white.se--;

        pair<ll,ll> black = qtd(X4-X3+1, Y4-Y3+1);
        if(X4-X3 == Y4-Y3 and abs(X4-Y4)&1 and (X4-X3+1)&1) white.fi--;
        if(X4-X3 == Y4-Y3 and (! abs(X4-Y4)&1) and (X4-X3+1)&1) white.se--;

        cout << (tot.fi + white.se) - black.fi << " ";
        cout << (tot.se + black.se) - white.se << endl;
        cout << tot.fi << " " << tot.se << " | " << white.fi << " " << white.se << " | " << black.fi << " " << black.se << endl;
    }
        

    return 0;
}

