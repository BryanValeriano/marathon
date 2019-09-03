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

const int T = 1e3;
ll v[T];
ll ans[T];
map<ll,int> id;
vector<ll> ord;


int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        int m, n; cin >> m >> n;
        for(int i = 0; i < n; i++) cin >> v[i];

        ll sec;
        int k = 1;

        while(v[k-1] == v[k]) k++;
        sec = __gcd(v[k-1], v[k]);
        ans[k] = sec;
        
        int tmp = sec;
        for(int i = k; i > 0; i--) {
            ans[i-1] = v[i-1]/tmp;
            tmp = ans[i-1];
        }
        
        for(int i = k; i < n; i++) {
            ans[i+1] = v[i]/sec;
            sec = ans[i+1];
        }

        for(int i = 0; i <= n; i++) ord.pb(ans[i]);
        sort(ord.begin(), ord.end());
        ord.resize(unique(ord.begin(), ord.end()) - ord.begin());

        for(int i = 0; i < ord.size(); i++) 
            id[ord[i]] = i;

        char base = 'A';

        cout << "Case #" << ++cont << ": ";
        for(int i = 0; i <= n; i++) 
            cout << (char)(base + id[ans[i]]);
        cout << endl;
        ord.clear();
        id.clear();
    }

    return 0;
}

