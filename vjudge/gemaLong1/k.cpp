#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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

int n;
vector<string> v;
unordered_map<string, vector<string>> g;
unordered_map<string, string> f;
unordered_map<string, int> in;

string lower(string s) {
    string x;
    for(int i = 0; i < s.size(); i++) x += tolower(s[i]);
    return x;
}

int rs(string x) {
    int r = 0;
    for(int i = 0; i < x.size(); i++) r += (x[i] == 'r');
    return r;
}

string best(string x, string y) {
    int a = rs(x);
    int b = rs(y);
    if(a < b) return x;
    if(b < a) return y;
    return (x.size() <= y.size()? x : y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s, t;

    for(int i = 0; i < n; i++) {
        cin >> s;
        s = lower(s);
        v.pb(s);
        in[s] = 0;
    }

    int m; cin >> m;
    while(m--) {
        cin >> s >> t;
        s = lower(s); t = lower(t);
        g[s].pb(t);
        in[t]++;
        in[s]++; in[s]--;
    }

    queue<string> lista;
    for(auto ok : in) if(ok.se == 0) lista.push(ok.fi);

    while(!lista.empty()) {

    }

    return 0;
}

