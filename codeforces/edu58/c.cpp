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
const int T = 1e5 + 10;
vii query;
vector<int> ve;
map<int,int>id;
int seg[T];
int maxi;

void undo() {
    for(int i = 0; i < maxi; i++) seg[i] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int q; cin >> q;
        undo();
        query.clear();
        id.clear();
        ve.clear();
        int l,r;
        while(q--) {
            cin >> l >> r;
            query.eb(l,r);
            ve.pb(l);
            ve.pb(r);
            ve.pb(l-1);
            ve.pb(r+1);
        }
        sort(ve.begin(), ve.end());
        ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
        for(int i = 0; i < ve.size(); i++) id[ve[i]] = i;
        maxi = ve.size();
        for(auto x : query) {
            seg[id[x.fi]]++;
            seg[id[x.se+1]]--;
        }
        for(int i = 1; i <= maxi; i++) {
            seg[i] += seg[i-1];
            cout << seg[i];
        }
        cout << endl;
        bool prim = false;
        bool seco = false;
        bool tem = false;
        int primeiro = 0;
        int segundo = 0;
        for(int i = 0; i <= maxi; i++) {
            if(seg[i] != 0 and prim == false) {
                prim = true;
                primeiro = i;
            }
            else if(seg[i] == 0 and prim == true and seco == false) {
                seco = true;
                segundo = i;
            }
            else if(seg[i] != 0 and prim == true and seco == true) {
                tem = true;
            }
        }
        if(tem == false) { cout << -1 << endl; continue; }
        for(auto x : query) {
            if(id[x.se] < segundo) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    }
    return 0;
}

