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
const int T = 182;


int main() {
    ios::sync_with_stdio(false);
    vector<int> ans(T,0);

    for(int i = 3; i <= 180; i++) {
        for(int j = 1; j <= i-2; j++) {
            if((180*j)%i) continue;
            if(!ans[(180*j)/i]) ans[(180*j)/i] = i;
        }
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << (ans[x]?ans[x]:360) << endl;
    }
    return 0;
}

