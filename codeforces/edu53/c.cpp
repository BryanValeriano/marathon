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

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    int fimx, fimy;
    cin >> fimx >> fimy;
    ll manhattan = abs(fimx) + abs(fimy);
    if(manhattan > n) {
        cout << -1 << endl;
        return 0;
    }
    int contx = 0;
    int conty = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') conty++;
        else if(s[i] == 'D') conty--;
        else if(s[i] == 'R') contx++; 
        else if(s[i] == 'L') contx--;
    }
    ll ans = 0; 
    ans += abs(fimx - contx);
    ans += abs(fimy - conty);
    cout << ans << endl;

    return 0;
}

