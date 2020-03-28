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
const int T = 1e6;

map<string,int> bag;
vector<int> g[T];
bool valid[T];
int in[T];
int cont;


int getId(string x) {
    if(bag.count(x)) return bag[x];
    return bag[x] = cont++;
}

vector<int> getIds(const vector<string> &tmp) {
    vector<int> v;
    for(auto x : tmp) v.pb(getId(x));
    return v;
}

vector<int> split(const string &s) {
    string x;
    vector<string> tmp;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') tmp.pb(x), x = "";
        else x += s[i];
    }
    vector<int> v = getIds(tmp);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;

    while(getline(cin,s)) {
        vector<int> v = split(s);
        valid[v[0]] = 1;
        for(int i = 1; i < v.size(); i++) {
            g[v[i]].pb(v[0]);
            in[v[0]]++;
        }
    }

    queue<int> fila;
    for(int i = 0; i < cont; i++)
        if(valid[i] and !in[i]) fila.push(i);

    int ans = 0;

    while(!fila.empty()) {
        int at = fila.front();
        fila.pop();
        ans++;
        for(int v : g[at]) {
            in[v]--;
            if(!in[v] and valid[v]) fila.push(v);
        }
    }

    cout << ans << endl;
    return 0;
}

