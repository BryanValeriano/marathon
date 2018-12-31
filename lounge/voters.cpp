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
    int a,b,c; cin >> a >> b >> c;
    int aux;
    map<int,int> id;
    set<int> ans;
    for(int i = 0; i < a+b+c; i++) {
        cin >> aux;
        id[aux]++;
        if(id[aux] > 1) ans.insert(aux);
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

