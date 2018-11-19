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
    int n, k; cin >> n >> k;
    map<int,int>id;
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        id[aux]++;
    }
    int maxi = -INF;
    for(auto x : id)
        maxi = max(maxi, x.se);
    int pCada = (maxi/k);
    if(maxi%k != 0) pCada++;
    if(pCada == 0) pCada = 1;
    int ans = 0;
    for(auto x : id) 
        ans += (pCada*k) - x.se;
    cout << ans << endl;

    return 0;
}

