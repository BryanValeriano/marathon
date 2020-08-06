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

unordered_map<string, int> bag;
unordered_map<int, int> sz;
vector<int> v;
int cont = 0;

int id(string x) {
    if(!bag.count(x)) {
        bag[x] = ++cont;
        sz[cont] = x.length();
    }
    return bag[x];
}

bool has(int x, int y) {
    for(int i = y+1; i < v.size(); i++) {
        int ok = 0;
        for(int j = i; j < v.size() and j-i+1 <= y-x+1; j++) {
            if(v[j] == v[x+(j-i)]) ok++;
            else break;
        }
        if(ok == y-x+1) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int tot = 0;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        v.pb(id(s));
        tot += sz[v.back()];
        if(i) tot++;
    }

    int best = tot;

    for(int i = 0; i < n; i++) {
        int fora = 0;
        for(int j = i; j < n; j++) {
            fora += sz[v[j]];
            if(has(i,j)) {
                best = min(best,tot-2*fora+2*(j-i+1)-2*(j-i));
                cout << i << " " << j << " = ";
                cout << tot-2*fora+2*(j-i+1)-2*(j-i) << endl;
            }
        }
    }

    cout << best << endl;
    return 0;
}

