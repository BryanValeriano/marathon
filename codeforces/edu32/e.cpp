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



int main() {
    ios::sync_with_stdio(false);
    int n;
    ll m,x;

    v1.insert(0);
    v2.insert(0);
    cin >> n >> m;

    ll ans = 0;

    for(int i = 0; i < n/2; i++) {
        cin >> x;
        set<ll> tmp;
        for(auto it : v1) tmp.insert((it+x)%m), ans = max(ans,it);
        for(auto it : tmp) v1.insert(it), ans = max(ans,it);
    }

    for(int i = n/2; i < n; i++) {
        cin >> x;
        set<ll> tmp;
        for(auto it : v2) tmp.insert((it+x)%m), ans = max(ans,it);
        for(auto it : tmp) v2.insert(it), ans = max(ans,it);
    }

    for(auto it : v1) {
        int precisa = (m-1) - it;    
        auto ok = v2.lower_bound(precisa);
        if(ok == v2.end()) ok--;
        while(ok != v2.begin() and it + *ok >= m) ok--;
        ans = max(ans, (it+ *ok) % m);
    }

    cout << ans << endl;

    return 0;
}

