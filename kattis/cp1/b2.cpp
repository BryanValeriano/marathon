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
typedef pair<string,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 17;
int n,m;

map<string, int> bag;
vector<int> ids;
int hate[T];
int hateG[T];
int has[T];
int hasG[T];
int cont;
int ans;

void init() {
    for(int i = 0; i < T; i++) hasG[i] = hateG[i] = 0;
    bag.clear();
    ids.clear();
    cont = 0;
    ans = n;
}

int id(string s) {
    if(bag.count(s)) return bag[s];
    has[cont] = 0;
    hate[cont] = 0;
    return bag[s] = cont++;
}

void solve(int tmp, int g) {
    if(g >= ans) return;
    if(tmp == ids.size()) { ans = min(ans,g); return; }
    int at = ids[tmp];

    int hs = 0;
    int ht = 0;

    for(int i = 1; i <= g; i++) {
        if((hateG[i] & has[at]) or (hate[at] & hasG[i])) continue;
        hs = hasG[i];
        ht = hateG[i];
        hasG[i] |= has[at];
        hateG[i] |= hate[at];
        solve(tmp+1,g);
        hasG[i] = hs;
        hateG[i] = ht;
    }

    hasG[g+1] = has[at];
    hateG[g+1] = hate[at];
    solve(tmp+1, g+1);
    hasG[g+1] = 0;
    hateG[g+1] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    while(n or m) {
        init();
        for(int i = 0; i < m; i++) {
            string s1,s2; cin >> s1 >> s2;
            hate[id(s1)] |= (1 << id(s2));
            has[id(s1)] |= (1 << id(s1));
            hate[id(s2)] |= (1 << id(s1));
            has[id(s2)] |= (1 << id(s2));
        }

        for(auto ok : bag) ids.pb(ok.se);
        solve(0,0);
        cout << max(1,ans) << endl;
        cin >> n >> m;
    }
    return 0;
}

