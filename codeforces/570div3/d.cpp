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
int v[T];
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) v[i] = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v[x]++;
        }

        priority_queue<int,vector<int>> pq;
        for(int i = 1; i <= n; i++) if(v[i]) pq.push(v[i]);
        
        int last = n+1;
        ll ans = 0;

        while(!pq.empty()) {
            ll at = pq.top();
            pq.pop();
            if(at >= last) at = last-1;
            ans += max(0ll,at);
            last = at;
        }
        
        cout << ans << endl;
    }

    
    
    return 0;
}

