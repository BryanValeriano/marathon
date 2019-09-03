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
string s, t;

ll cont() {
    int q1 = 0;
    int q2 = 0;

    for(int i = 0; i < s.size(); i++) 
        if(s[i] == '4') q1++;
    for(int i = 0; i < s.size(); i++) 
        if(t[i] == '4') q2++;
    
    if(q1 == q2) return 0;
    ll ans = abs(q1 - q2);
    if(q1 > q2) {
        for(int i = 0; i < s.size(); i++) {
            if(q1 > q2 and s[i] == '4' and t[i] == '7') {
                q1--;
                s[i] = '7';
            }
        }
    }
    else if(q1 < q2) {
        for(int i = 0; i < s.size(); i++) {
            if(q1 < q2 and s[i] == '7' and t[i] == '4') {
                q1++;
                s[i] = '4';
            }
        }
    }
    return ans;
}

ll dist() {
    ll ans = 0;

    for(int i = 0; i < s.size(); i++) 
        if(s[i] != t[i]) ans++;

    return ans/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> t;
    ll ans = 0;
    ans += cont();
    ans += dist();
    cout << ans << endl;

    return 0;
}

