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
    string s, t;
    map<char,int> ss;
    map<char,int> tt;
    int dif = 0;
    cin >> s >> t;
    if(t.size() != s.size()) { cout << "NO" << endl; return 0; }
    for(int i = 0; i < s.size(); i++) {
        ss[s[i]]++;
        tt[t[i]]++;
        if(s[i] != t[i]) dif++;
    }
    if(dif > 2) { cout << "NO" << endl; return 0; }
    map<char,int>::iterator it = tt.begin();
    for(auto xs : ss) {
        if(xs.fi != it->fi or xs.se != it->se) {
            cout << "NO" << endl; return 0;
        }
        it++;
    }
    cout << "YES" << endl;
    return 0;
}

