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

int n,m;
priority_queue<int, vector<int> > pq;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    while(m--) {
        int at = pq.top(); 
        pq.pop();
        if(at) at /= 2;
        pq.push(at);
    }

    ll ans = 0;
    while(!pq.empty()) ans += pq.top(), pq.pop();
    cout << ans << endl;

        

    
    
    return 0;
}

