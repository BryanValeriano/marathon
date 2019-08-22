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

priority_queue<ll,vector<ll>, greater<ll> > pq;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    ll ans = 0;
    if(!(pq.size()&1)) pq.push(0);


    while(pq.size() > 1) {
        ll x,y,z;
        x = y = z = 0;
        if(!pq.empty()) x = pq.top(), pq.pop();
        if(!pq.empty()) y = pq.top(), pq.pop();
        if(!pq.empty()) z = pq.top(), pq.pop();
        pq.push(x+y+z);
        ans += x+y+z;
    }

    cout << ans << endl;

    return 0;
}

