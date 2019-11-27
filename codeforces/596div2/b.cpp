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
const int T = 2e5 + 5;
const int N = 1e6 + 5;
int v[T];
int qtd[N];
int n,k,d;
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin>> n >> k >> d;
        for(int i = 0; i < n; i++) cin >> v[i];
        int ans = INF; int cont = 0;
        for(int i = 0; i < d; i++) {
            if(!qtd[v[i]]) cont++;
            qtd[v[i]]++;
        }
        for(int i = d; i < n; i++) {
            ans = min(ans,cont);
            qtd[v[i-d]]--;
            if(!qtd[v[i-d]]) cont--;
            if(!qtd[v[i]]) cont++;
            qtd[v[i]]++;
        }
        for(int i = 0; i < n; i++) qtd[v[i]] = 0;
        ans = min(ans,cont);
        cout << ans << endl;
    }

    return 0;
}

