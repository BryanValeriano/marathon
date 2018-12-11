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
int v[110];
char ans[110];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    map<int,int> id;
    for(int i = 0; i < n; i++) { 
        cin >> v[i];
        id[v[i]]++;
    }
    int ums = 0;
    int outs = 0;
    for(auto x : id) { 
        if(x.se == 1) ums++;
        else if(x.se >= 3) outs++;
    }
    if(ums == 0) { cout << "YES" << endl; for(int i = 0; i < n; i++) cout << "A"; cout << endl; return 0; }
    if(ums > 0 and ums % 2 != 0 and outs == 0) { cout << "NO" << endl; return 0; }
    if(ums % 2 == 0) {
        cout << "YES" << endl;
        int cont = 1;
        for(int i = 0; i < n; i++) {
            if(id[v[i]] == 1) {
                if(cont % 2 == 0) cout << 'B';
                else cout << 'A';
                cont++;
            }
            else cout << 'A';
        }
        cout << endl;
        return 0;
    }
    cout << "YES" << endl;
    int cont = 1;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(id[v[i]] == 1) {
            if(cont % 2 == 0) cout << 'B';
            else cout << 'A';
            cont++;
        }
        else if(id[v[i]] >= 3 and flag) { cout << 'B'; flag = false; }
        else cout << 'A';
    }
    cout << endl;

    return 0;
}

