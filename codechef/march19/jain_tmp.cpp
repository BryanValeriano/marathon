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
const int T = 1e5 + 3;

//a = 0, e = 1, i = 2, o = 3, u = 4
bitset<T> le[5];
bitset<5> pal[T];
int n;

//ll combs() {
//    ll ans = 0;
//    memset(dp, 0, sizeof dp);
//
//    for(int i = 1; i < pow(2,5); i++) {
//        bitset<5> x(i);
//        bitset<5> y(~x);
//        if(dp[x.to_ulong()][y.to_ulong()] or dp[y.to_ulong()][x.to_ulong()]) continue; 
//        bitset<T> xx;
//        bitset<T> yy;
//        bitset<T> tt;
//        xx.set(), yy.set(), tt.set();
//        for(int j = 0; j < 5; j++) { 
//            if(x[j]) xx &= le[j];
//            if(y[j]) yy &= le[j];
//        }
//        tt = (xx&yy);
//        xx ^= tt;
//
//        for(int k = 0; k < 3; k++)  
//            cout << xx[k]; 
//        cout << endl;
//        for(int k = 0; k < 3; k++)  
//            cout << yy[k]; 
//        cout << endl;
//        for(int k = 0; k < 3; k++)  
//            cout << tt[k]; 
//        cout << endl;
//
//        cout << x << " " << y << " " << xx.count() << " " << yy.count() << " " << tt.count() << endl;
//        if(x.count() != 5) ans += xx.count() * yy.count();
//        else ans += xx.count();
//        dp[x.to_ulong()][y.to_ulong()] = true;
//    }
//
//    return ans;
//}

ll n2() {
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        bitset<5> neg(~pal[i]);
        bitset<T> comp;
        comp.set();
        for(int j = 0; j < 5; j++)
            if(neg[j]) comp &= le[j];
        ans += comp.count();
        if(comp.count()) {
            cout << i << endl;
            for(int j = 0; j < 3; j++) cout << comp[j];
            cout << endl;
        }
    }
    return ans;
}

int ind(char x) {
    if(x == 'a') return 0;
    if(x == 'e') return 1;
    if(x == 'i') return 2;
    if(x == 'o') return 3;
    if(x == 'u') return 4;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < 5; i++) le[i].reset();
        for(int i = 0; i < n; i++) {
            string x; cin >> x;
            pal[i].reset();
            for(int j = 0; j < x.size(); j++) {
                le[ind(x[j])].set(i, true);
                pal[i].set(ind(x[j]), true);
            }
        }
        cout << n2()/2 << endl;
    }
    return 0;
}

