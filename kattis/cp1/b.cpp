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
int has[T];
int cont;

void init() {
    bag.clear();
    ids.clear();
    cont = 0;
}

int id(string s) {
    if(bag.count(s)) return bag[s];
    has[cont] = 0;
    hate[cont] = 0;
    return bag[s] = cont++;
}

int solve(int at) {
    if(at == ids.size()) return 0;
    int ans = solve(at+1);
    int lastHas[T];
    int lastHate[T];

    for(auto x : ids) {
        if((has[x] & has[at]) or (has[x] & hate[at]) or (hate[x] & has[at])) continue;
        for(auto y : ids) {
            if((has[y] & has[at]) or (has[y] & has[x])) {
                lastHas[y] = has[y];
                lastHate[y] = hate[y];
                has[y] = (has[at] | has[x]);
                hate[y] = (hate[at] | hate[x]);
            }
        }
        ans = max(ans,solve(at+1)+1);
        for(auto y : ids) {
            if((has[y] & has[at]) or (has[y] & has[x])) {
                has[y] = lastHas[y];
                hate[y] = lastHate[y];
            }
        }
    }

    return ans;
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

        for(int i = cont; i < n; i++) {
            id(to_string(i));
            has[id(to_string(i))] = (1 << id(to_string(i)));
        }

        for(auto ok : bag) ids.pb(ok.se);
        int ans = cont;
        cout << ans-solve(0) << endl;
        cin >> n >> m;
    }
    return 0;
}

