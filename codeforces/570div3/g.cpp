#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< pair<ll,ll> > vii;
const int INF = 0x3f3f3f3f;
const int T = 2e5 + 5;
int v[T];
int out[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) v[i] = 0, out[i] = 0;
        for(int i = 0; i < n; i++) {
            int x,y; cin >> x >> y;
            v[x]++;
            out[x] += y;
        }

        priority_queue<ii,vii> pq;
        priority_queue<ii,vii> pq2;
        for(int i = 1; i <= n; i++) if(v[i]) pq.emplace(v[i],out[i]);

        ll last = n+1;
        ll ans = 0;
        ll dlk = 0;

        while(!pq.empty() or !pq2.empty()) {
            while(!pq.empty() and pq.top().fi >= last-1) {
                ii at = pq.top();
                pq.pop();
                pq2.emplace(at.se,at.fi);
            }

            if(!pq2.empty()) {
                ii at = pq2.top();
                pq2.pop();
                at.se = min(at.se,last-1);

                last = at.se;
                ans += max(0ll,at.se);
                if(at.se > 0) dlk += min(at.se,at.fi);
            }

            if(pq2.empty() and !pq.empty()) {
                ii at = pq.top();
                pq.pop();
                pq2.emplace(at.se,at.fi);
                last = min(last,at.fi+1);
            }
        }

        cout << ans << " " << dlk << endl;
    }



    return 0;
}


