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
const ll INF = 0x3f3f3f3f3f3f3f;
ll B;
ll G;
ll C;
ll um[3];
ll dois[3];
ll tres[3];
string ans;
ll res;

void solve() {
    res = INF;
    ll tmp;

    //BCG
    tmp = (B - um[0]) + (C - dois[2]) + (G - tres[1]);
    if(tmp < res) { res = tmp; ans = "BCG"; }

    //BGC
    tmp = (B - um[0]) + (G - dois[1]) + (C - tres[2]);
    if(tmp < res) { res = tmp; ans = "BGC"; } 

    //CBG
    tmp = (C - um[2]) + (B - dois[0]) + (G - tres[1]);
    if(tmp < res) { res = tmp; ans = "CBG"; }

    //CGB
    tmp = (C - um[2]) + (G - dois[1]) + (B - tres[0]);
    if(tmp < res) { res = tmp; ans = "CGB"; }

    //GBC
    tmp = (G - um[1]) + (B - dois[0]) + (C - tres[2]);
    if(tmp < res) { res = tmp; ans = "GBC"; }

    //GCB
    tmp = (G - um[1]) + (C - dois[2]) + (B - tres[0]);
    if(tmp < res) { res = tmp; ans = "GCB"; }
}

int main() {
    ios::sync_with_stdio(false);
    int aux1;
    int aux2;
    int aux3;
    while(cin >> aux1) {
        B = C = G = 0;
        memset(um, 0, sizeof um);
        memset(dois, 0, sizeof dois);
        memset(tres, 0, sizeof tres);
        cin >> aux2 >> aux3;
        um[0] += aux1; um[1] += aux2; um[2] += aux3;
        B += aux1;
        G += aux2;
        C += aux3;
        for(int i = 0; i < 2; i++) {
            cin >> aux1 >> aux2 >> aux3;
            if(i == 0) { dois[0] += aux1; dois[1] += aux2; dois[2] += aux3; }
            else { tres[0] += aux1; tres[1] += aux2; tres[2] += aux3; }
            B += aux1;
            G += aux2;
            C += aux3;
        }
        solve(); 
        cout << ans << " " << res << endl;
    }
    return 0;
}

