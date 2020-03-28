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
bool vis[10];
int n;

bool ok(const vector<int> &v, const vector<int> &p, bool print) {
    if(print) {
        for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
        for(int i = 0; i < v.size(); i++) cout << p[i] << " ";
        cout << endl;
        for(int i = 0; i < v.size(); i++) cout << (v[i]+p[i])%n+1 << " ";
        cout << endl << endl;
    }
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < v.size(); i++) {
        int x = (v[i]+p[i])%n+1;
        if(vis[x]) return 0;
        vis[x] = 1;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> v;
    vector<int> p;
    for(int i = 1; i <= n; i++) v.pb(i), p.pb(i);
    int ans = 0;
    int qtd = 0;

    do {
        do {
            qtd++;
            if(!ok(v,p,0)) ok(v,p,1), ans++;
        } while(next_permutation(p.begin(), p.end()));
        sort(p.begin(), p.end());
    } while(next_permutation(v.begin(), v.end()));

    cout << ans << " " << qtd << endl;

    return 0;
}

