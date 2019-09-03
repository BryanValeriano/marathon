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
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int aux;
    vector<int>ans;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        v[aux]++;
        ans.pb(aux);
    }
    for(int i = 0; i < n; i++) {
        if(v[i] != 0 and v[n - i] != i) {
            //cout << i << " " << v[i] << " | " << v[n-i] << endl;
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    for(auto x : ans) cout << x+1 << " ";
    cout << endl;
           

    return 0;
}

