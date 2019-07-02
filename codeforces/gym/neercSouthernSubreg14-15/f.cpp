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

int n, k; 
vector<ll> v;

ii search() { 
    ll ans = 0;
    int im = 0, jm = 0, i = 0, j = 0;
    ll cont = 0;
    while(true) {
        if(j == v.size()-1) break;
        if(j-i < k) {
            cont += v[++j];
            if(j-i == k) cont -= v[i++];
        } else {
            cont -= v[i++];
        }

        if(cont > ans) {
            im = i;
            jm = j;
            ans = cont;
        }
    }
    
    return ii(im, jm);

}

int main() {
    ios_base::sync_with_stdio(false);

    cin >>n >>k;
    
    for(int i = 0; i < n; i++) {
        ll a; cin >>a;
        v.pb(a);
    }

    ll ans = 0;
    
    ii s1 = search();
    for(int i = s1.fi; i <= s1.se; i++) {
        ans += v[i];
        v[i] = 0;
    }

    ii s2 = search();
    for(int i = s2.fi; i <= s2.se; i++) {
        ans += v[i];
    }

    cout <<ans <<endl;
    return 0;
}

