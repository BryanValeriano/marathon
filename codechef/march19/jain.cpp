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
const int T = 1e5 + 3;

bitset<T> le[5];
bitset<5> pal[T];
int dp[33][33];
int n;

ll n2() {
    ll ans = 0;
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++) {
        if(pal[i].count() == 5) { ans += n-1; continue; }
        bitset<5> neg(~pal[i]);

        int x = pal[i].to_ulong();
        int y = neg.to_ulong();
        if(dp[x][y]) { ans += dp[x][y]; continue; }

        bitset<T> comp;
        comp.set();
        for(int j = 0; j < 5; j++)
            if(neg[j]) comp &= le[j];
        int xx = comp.count();
        dp[x][y] = xx;
        ans += xx;
    }
    return (ans>>1);
}

int ind(char x) {
    if(x == 'a') return 0;
    if(x == 'e') return 1;
    if(x == 'i') return 2;
    if(x == 'o') return 3;
    if(x == 'u') return 4;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < 5; i++) le[i].reset();
        for(int i = 0; i < n; i++) {
            string x; cin >> x;
            pal[i].reset();
            for(int j = 0; j < x.size(); j++) {
                le[ind(x[j])].set(i, true);
                pal[i].set(ind(x[j]), true);
            }
        }
        cout << n2() << endl;
    }
    return 0;
}

