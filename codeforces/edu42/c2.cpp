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
set<ll>vis;
set<ll>sq;
set<ll>resp;

void busc(ll x) {
    if(vis.count(x)) return;
    string tmp = to_string(x);
    if(tmp[0] == '0') return;
    if(sq.count(x)) { resp.insert(x); }
	vis.insert(x);
    for(int i = 0; i < tmp.size(); i++) {
        string h;
        for(int j = 0; j < tmp.size(); j++) 
            if(j != i) h += tmp[j];
        if(h.size() == 0) break; 
        ll x = 0;
        stringstream y(h);
        y >> x;
        busc(x);
    }
}       

void pre() {
    for(int i = 1; i <= 44722; i++)
        sq.insert(i*i);
}

int main() {
    //ios::sync_with_stdio(false);
    pre();
    cin >> num;
    busc(num); 
    string tmp = to_string(num);
    if(resp.size() == 0) { cout << -1 << endl; return 0; }
    ll x = *(resp.rbegin());
    string id = to_string(x);
    cout <<  (tmp.size() - id.size()) << endl;
    return 0;
}
