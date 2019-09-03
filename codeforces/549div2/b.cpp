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

int cary(int pos) {
    int ans = pos;
    s[pos] = '9';
    if(pos > 0) {
        if(s[pos-1] == '0') ans = cary(pos-1);
        else s[pos-1]--;
    } else s[pos] = '1';
    return ans;
}

ll calc() {
    ll ans = 1;
    bool flag = false;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '0') flag = true;
        if(flag) ans *= (s[i] - '0');
    }
    cout << s << " " << ans << endl;
    return ans;
}

ll melhor() {
    ll at = calc();
    int i = s.size() - 1;
    while(i >= 1) {
        s[i] = '9';
        int last = i;
        if(s[i-1] == '0') cary(i-1);
        else s[i-1]--;
        at = max(at, calc());
        i = last;
        i--;
    }
    return at;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    cout << melhor() << endl;
    return 0;
}

