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

const int T = 1010;
int v[T];
vector<int> ans;

bool ok() {
    for(int i = 1; i < ans.size(); i++) {
        if(i&1 and ans[i] < ans[i-1]) return false;
        if((!(i&1)) and ans[i] > ans[i-1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    int ini = 0;
    int fim = n-1;
    sort(v, v+n);

    while(ini <= fim) {
        ans.pb(v[ini]);
        if(ini != fim) ans.pb(v[fim]);
        ini++;
        fim--;
    }
    if(!ok()) { cout << "Impossible" << endl; return 0; }
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

