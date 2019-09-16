#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5+3;
ll v[T];
int n;
set<ii> bag;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> v[i], v[i] += v[i-1];
        bag.insert({v[i],i});
    }

    ll dist = INF;
    ll ini = 0;

    for(int i = 1; i <= n; i++) {
        ll at = v[i] - v[i-1];
        ll prox = v[i] - at;
        auto it = bag.lower_bound({prox,i});
        if(it == bag.end()) continue;
        if(it->fi == prox && it->se >= i)
            if(it->se - i < dist)
                dist = it->se - i, ini = i;
    }

    if(dist == INF) { cout << -1  << endl; return 0; }
    cout << ini << " " << dist+1 << endl;

    return 0;
}

