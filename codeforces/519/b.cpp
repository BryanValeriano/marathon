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

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int aux;
    vector<int> v(n+1), b(n);
    v.pb(0);
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        v[i] = aux;
        b[i-1] = v[i] - v[i-1];
    }
    vector<int>resp;
    for(int k = 1; k <= n; k++) {
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            if(v[i] != v[i-1] + b[(i-1)%k]) {
                flag = false; break;
            }
        }
        if(flag) resp.pb(k);
    }
    cout << resp.size() << endl;
    for(auto id : resp) 
        cout << id << " "; cout << endl;
    return 0;
}

