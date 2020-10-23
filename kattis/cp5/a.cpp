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
typedef pair<string,bool> si;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 5e4+5;

vector<string> v;
vector<si> ve;
map<string,bool> id;
map<string,int> pos;
int top, offset;

void add(string s) {
    v.pb(s);
    id[s] = 1;
    pos[s] = top-offset;
    top++;
}

bool ok() {
    for(int i = 0; i < ve.size(); i++)
        if(id[ve[i].fi] != ve[i].se) return 0;
    return 1;
}

int someR() {
    int r = 0;
    int l = INF;

    for(int i = 0; i < ve.size(); i++) {
        if(id[ve[i].fi] != ve[i].se) {
            if(ve[i].se == 1) return 0;
            int tmp = top-pos[ve[i].fi]-offset;
            r = max(r,tmp);
        }
        else if(ve[i].se) {
            int tmp = top-pos[ve[i].fi]-offset;
            l = min(l,tmp);
        }
    }

    if(r < l) return r;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
        char op;
        string s;
        int k;

        cin >> op;
        if(op == 'E') {
            cin >> s;
            add(s);
        }
        else if(op == 'D') {
            cin >> k;
            while(k--) {
                id[v.back()] = 0;
                v.pop_back();
                offset++;
            }
        } else {
            int m; cin >> m;
            ve.clear();
            for(int i = 0; i < m; i++) {
                cin >> s;
                if(s[0] == '!') ve.eb(s.substr(1),0);
                else ve.eb(s,1);
            }
            if(ok()) cout << "Yes\n";
            else {
                int r = someR();
                if(r) cout << r << " Just A Dream\n";
                else cout << "Plot Error\n";
            }
        }
    }

    return 0;
}

