#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 705;


string compress(string s, int sz) {
    string ans;
    vector<bool> vis(s.size(),0);
    for(int i = sz; i+sz-1 < s.size();) {
        bool ok = 1;
        for(int j = i-sz; j < i; j++) ok &= (s[j] == s[j+sz]);
        if(ok) {
            for(int j = i-sz; j < i; j++) vis[j] = 1;
            i += sz;
        } else i++;
    }
    for(int i = 0; i < s.size(); i++) {
        if(!vis[i]) ans += s[i];
        else {
            ans += "(" + s.substr(i, sz) + ")";
            i += 2*sz-1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    for(int i = s.size()/2; i >= 1; i--) {
        s = compress(s,i);
        cerr << i << " " << s << endl;
    }
    cerr << s << endl;
    cout << s.size() << endl;
}

