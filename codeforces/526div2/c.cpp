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
const int mod = 1e9 + 7;
const int T = 1e5 + 10;

vector<ll> ans;

int main() {
    ios::sync_with_stdio(false);
    string t; cin >> t;
    string s;
    for(int i = 0; i < t.size(); i++)
        if(t[i] == 'a' or t[i] == 'b') s += t[i];

    int as = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') as++;
        if(s[i] == 'b' and i-1 >= 0 and s[i-1] == 'a') { ans.pb(as); as = 0; }
    }
    if(*s.rbegin() == 'a') ans.pb(as);

    ll resp = 1;
    for(auto x : ans) 
        resp = (resp * (x+1)) % mod;
    resp--;
    cout << resp << endl;
    return 0;
}

