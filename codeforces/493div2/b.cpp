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

const int T = 110;
int v[T];
int par[T];
int impar[T];

int main() {
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i]&1) impar[i]++;
        else par[i]++;
    }

    for(int i = 1; i < n; i++) {
        par[i] += par[i-1];
        impar[i] += impar[i-1];
    }
    
    vector<int> ans;
    for(int i = 0; i < n-1; i++) 
        if(par[i] == impar[i]) ans.eb(abs(v[i] - v[i+1]));

    sort(ans.begin(), ans.end());

    int acum = 0;
    for(int i = 0; i <  ans.size(); i++) {
        acum += ans[i];
        if(acum > k) { cout << i << endl; return 0; }
    }
    cout << ans.size() << endl;

    return 0;
}

