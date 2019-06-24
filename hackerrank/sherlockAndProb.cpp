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

const int T = 2e5 + 5;
int ini = 1e5+1;
ll n,k,fim;
ll v[T];
string s;
ll ans;
ll tot;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n >> k;
        tot = n*n;
        ans = 0;
        fim = ini+n;
        cin >> s;

        for(int i = ini; i < fim; i++) 
            v[i] = (s[i-ini] == '1');

        for(int i = ini+1; i < fim; i++) 
            v[i] += v[i-1];

        for(int i = ini; i < fim; i++) {
            ll ok = v[i] - v[i-k-1];
            ans += ok*ok;
            ll nok = v[i-1] - v[i-k-1];
            ans -= nok*nok;
        }
        
        ll gcd = 1;
        if(ans > 0) gcd = __gcd(ans,tot);   
        if(ans == 0) cout << "0/1" << endl;
        else cout << ans/gcd << "/" << tot/gcd << endl; 
            
    }

    return 0;
}

