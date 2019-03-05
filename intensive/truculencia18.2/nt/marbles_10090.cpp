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
const ll INF = 0x3f3f3f3f3f3f3f;

ll c1,n1;
ll c2,n2;
ll x,y,d;

void gcd(ll a, ll b) {
    if(b == 0) { x = 1; y = 0; d = a; return; }
    gcd(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b) * y; 
    x = x1;
    y = y1;
}

int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t != 0) {
        cin >> c1 >> n1 >> c2 >> n2;
        if(t % __gcd(n1,n2)) {
            cout << "failed" << endl;
            cin >> t;
            continue;
        }
        gcd(n1,n2);
        x *= t/d, y *= t/d;
    
        if(x < 0) {
            ll passo;
            passo = d*y/n1;
            x += passo*n2/d;
            y -= passo*n1/d;
        }
        if(y < 0) {
            ll passo;
            passo = d*x/n2;
            x -= passo*n2/d;
            y += passo*n1/d; 
        }
        
        ll ans1;
        ll passo;
        passo = d*y/n1;
        ll a = x + n2*passo/d;
        ll b = y - n1*passo/d;
        ans1 = a*c1 + b*c2;
        if(a < 0 or b < 0) ans1 = INF;
        

        ll ans2;
        passo = d*x/n2;
        ll aa = x - n2*passo/d;
        ll bb =  y + n1*passo/d;
        ans2 = aa*c1 + bb*c2;
        if(aa < 0 or bb < 0) ans2 = INF;

        if(ans1 < INF or ans2 < INF) {
            if(ans1 < ans2) cout << a << " " << b << endl;
            else cout << aa << " " << bb << endl;
        } else cout << "failed" << endl;
        
        cin >> t;
    }
    return 0;
}

