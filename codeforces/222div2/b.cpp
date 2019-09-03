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

const int T = 1e5 + 3;

struct node {
    int tempo, pos, tipo;
    bool operator < (const node &b) const {
        return tempo < b.tempo;
    }
};

bitset<T> ans[2];
vector<node> v;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a,b;

    for(int i = 0; i < n/2; i++) ans[0][i] = ans[1][i] = 1;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.pb({a,i,0});
        v.pb({b,i,1});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) ans[v[i].tipo][v[i].pos] = 1;

    for(int i = 0; i < n; i++) cout << ans[0][i];
    cout << endl;
    for(int i = 0; i < n; i++) cout << ans[1][i];
    cout << endl;

    return 0;
}

