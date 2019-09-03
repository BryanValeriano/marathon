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

string s;

int solve(int at, int mask, int pegos) {
    if(at == 7) return __builtin_popcount(mask);

    int ans = solve(at+1, mask, pegos); 

    if((pegos & (1 << at)) == 0) { 
        int newpegos = pegos | (1 << at);
        ans = max(ans, solve(at+1, mask | (1<< (s[at] - 64)), newpegos));
        
        for(int i = at+1; i < 7; i++) {
            int comb = (s[at] - 64 + s[i] - 64);
            if(comb < 6 and (pegos & (1<<i)) == 0) ans = max(ans, solve(at+1, mask | (1<<comb), newpegos | (1<<i)));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        int x = solve(0,0,0);
        if(x == 5) cout << "YES" << endl;
        else cout << "NO" << endl;
    } 
    return 0;
}

