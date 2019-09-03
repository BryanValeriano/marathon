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
ll num;
unordered_set<ll>vis;
unordered_set<ll>sq;
set<string>resp;
bool flag = false;
queue<int> bfs;

void busc(ll k) {
    bfs.push(k);
    while(!bfs.empty()) {
        ll x = bfs.front();
        bfs.pop();

        if(flag) return;
        if(vis.count(x)) continue;
        string tmp = to_string(x);
        if(tmp[0] == '0') continue;
        vis.insert(x);
        if(sq.count(x)) { resp.insert(tmp); flag = true; }
        for(int i = 0; i < tmp.size(); i++) {
            string h;
            for(int j = 0; j < tmp.size(); j++) 
                if(j != i) h += tmp[j];
            if(h.size() == 0) break; 
            ll t = 0;
            stringstream y(h);
            y >> t;
            bfs.push(t);
        }
    }
}       

void pre() {
    for(int i = 1; i <= 44722; i++)
        sq.insert(i*i);
}

int main() {
    ios::sync_with_stdio(false);
    pre();
    cin >> num;
    busc(num); 
    string tmp = to_string(num);
    if(resp.size() == 0) { cout << -1 << endl; return 0; }
    string id = *(resp.rbegin());
    cout <<  (tmp.size() - id.size()) << endl;
    return 0;
}

