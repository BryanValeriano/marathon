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
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int aux;
    for(ll i = 0; i < n; i++) {
        cin >> aux;
        a.pb(aux);
    }
    sort(a.begin(), a.end());
    for(ll i = 0; i < m; i++) {
        cin >> aux;
        cout << upper_bound(a.begin(), a.end(), aux) - a.begin() << " ";
    }
    cout << endl;
    return 0;
}

