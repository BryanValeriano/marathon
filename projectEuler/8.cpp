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

int ok;
ll solve(string s) {
    ll x = 1;
    int z = 0;

    for(int i = 0; i < ok; i++) {
        if(s[i] == '0') z++;
        else x *= (s[i]-'0');
    }

    ll ans = 0;
    if(!z) ans = x;

    for(int i = ok; i < s.size(); i++) {
        if(s[i-ok] != '0') x /= (s[i-ok] - '0');
        else z--;

        if(s[i] != '0') x *= (s[i] - '0');
        else z++;

        if(!z) ans = max(ans,x);
    }

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s >> ok;
    cout << solve(s) << endl;
    return 0;
}

