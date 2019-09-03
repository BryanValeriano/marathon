#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

bool flag;
int z;
vector<pair<string, int> > v;
unordered_set<string> bag;


void trans(string s) {
    string x = "";
    string y;
    int i = 1;
    while(s[i] != ',') x += s[i++]; 
    i++;
    while(s[i] != ')') y += s[i++];
    if(x == "") { flag = false; return; }
    int xx = stoi(x);
    v.pb({y,xx});
}

void init() {
    v.clear();
    bag.clear();
    flag = true;
}

void solve() {
    sort(v.begin(), v.end(), [&] (const si &a, const si &b) { 
        if(a.fi.size() < b.fi.size()) return true; 
        else if(b.fi.size() < a.fi.size()) return false;
        else for(int i = 0; i < a.fi.size(); i++) {
            if(a.fi[i] == 'L' and b.fi[i] == 'R') return true;
            else if(a.fi[i] == 'R' and b.fi[i] == 'L') return false;
        }
        return false;
    });

    if(!v.size() or v[0].fi != "") { cout << "not complete" << endl; return; }
    bag.insert(v[0].fi);

    for(int i = 1; i < v.size(); i++) {
        if(v[i].fi == "") { cout << "not complete" << endl; return; }
        string z = v[i].fi;
        z.pop_back();
        if(!bag.count(z) or bag.count(v[i].fi)) { cout << "not complete" << endl; return; }
        else bag.insert(v[i].fi);

    }
    
    for(int i = 0; i < v.size(); i++) cout << v[i].se, cout << (i+1 == v.size()? "" : " ");
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    init();
    while(cin >> s) {
        if(s == "()") solve(), init();
        else trans(s);
    }
    return 0;
}

