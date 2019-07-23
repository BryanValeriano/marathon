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

const int T = 1e6 + 5;
ll e[T];

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    ll x = 0;
    ll ans = 0;

    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'v' and s[i-1] == 'v') x++;
        else if(s[i] == 'o') e[i] = x;
    }

    x = 0;

    for(int i = s.size() - 2; i >= 0; i--) {
        if(s[i] == 'v' and s[i+1] == 'v') x++;
        else if(s[i] == 'o') ans += x*e[i];
    }

    cout << ans << endl;

    return 0;
}

