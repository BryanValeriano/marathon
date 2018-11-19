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
ll t, inix, iniy, fimx, fimy;
map<char, pair<ll,ll> >id;
string row;

ll solve(ll x, ll y) {
    ll dist = abs(inix - fimx) + abs(iniy - fimy);
    for(int i = 0; i < t; i++) {
        ll newdist =  abs((x + id[row[i]].fi) - fimx) + abs((y + id[row[i]].se) - fimy);
        if(newdist < dist) {
            x += id[row[i]].fi;
            y += id[row[i]].se;
            dist = newdist;
        }
        if(dist == 0) return i+1;
    }
    return INF; 
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t >> inix >> iniy >> fimx >> fimy;
    cin >> row;
    id['S'] = ii(0,-1);
    id['N'] = ii(0,1);
    id['E'] = ii(1,0);
    id['W'] = ii(-1,0);
    int ans = solve(inix,iniy);
    cout << (ans == INF? -1 : ans) << endl;

    return 0;
}

