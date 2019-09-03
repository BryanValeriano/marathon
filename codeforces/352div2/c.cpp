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

long double ax,ay,bx,by,tx,ty;

vector< pair<long double, long double> > v;
vector< pair<long double, int> > adil;
vector< pair<long double, int> > bera;

int main() {
    ios::sync_with_stdio(false);
    ll AX,AY,BX,BY,TX,TY;
    cin >> AX >> AY >> BX >> BY >> TX >> TY;
    ax = AX; ay = AY; bx = BX; by = BY; tx = TX; ty = TY;

    int n; cin >> n;
    ll uu,xx;
    long double u, x;

    for(int i = 0; i < n; i++) {
        cin >> uu >> xx;
        u = uu; x = xx;
        v.eb(u,x);
        adil.eb(hypot(abs(tx - u), abs(ty - x)) - hypot(abs(ax-u), abs(ay-x)), i);
        bera.eb(hypot(abs(tx - u), abs(ty - x)) - hypot(abs(bx-u), abs(by-x)), i);
    }

    sort(adil.begin(), adil.end());
    reverse(adil.begin(), adil.end());
    sort(bera.begin(), bera.end());
    reverse(bera.begin(), bera.end());

    int inia = 0;
    int inib = 0;
    long double ans = 0;
    int oper = 0;

    if(n == 1) {
        if(adil[0].fi >= bera[0].fi) oper = 1;
        else oper = 2;
    }

    if(adil[0].fi < 0 and bera[0].fi < 0) {
        if(adil[0].fi >= bera[0].fi) oper = 1;
        else oper = 2;
    }

    if(adil[0].fi >= 0 and bera[0].fi < 0) oper = 1; 
    if(adil[0].fi < 0 and bera[0].fi >= 0) oper = 2; 
    
    if(oper == 0) {
        if(adil[0].se == bera[0].se) {
            if(adil[0].fi + bera[1].fi >= adil[1].fi + bera[0].fi) {
                inia = 0;
                inib = 1;
            } else {
                inia = 1;
                inib = 0;
            }
        } else { inia = 0; inib = 0; }

        if(adil[inia].fi >= 0 and bera[inib].fi < 0) oper = 1; 
        if(adil[inia].fi < 0 and bera[inib].fi >= 0) oper = 2;
    }
        
    if(oper == 1) { inia = 0;}
    if(oper == 2) { inib = 0;}

    inia = adil[inia].se; inib = bera[inib].se;

    if(oper == 1) { inib = -1;}
    if(oper == 2) { inia = -1;}

    if(oper != 2) ans += hypot(abs(v[inia].fi - ax), abs(v[inia].se - ay));
    if(oper != 1) ans += hypot(abs(v[inib].fi - bx), abs(v[inib].se - by));

    if(oper != 2) ans += hypot(abs(v[inia].fi - tx), abs(v[inia].se - ty));
    if(oper != 1) ans += hypot(abs(v[inib].fi - tx), abs(v[inib].se - ty));

    for(int i = 0; i < n; i++) {
        if(i == inia or i == inib) continue;
        ans +=  hypot(abs(v[i].fi - tx), abs(v[i].se - ty));
        ans +=  hypot(abs(v[i].fi - tx), abs(v[i].se - ty));
    }
    
    cout << fixed << setprecision(8) << ans << endl; 

    return 0;
}

