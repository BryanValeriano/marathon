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
    int row[n+10];
    ll ans[n+10];
    for(int i = 1; i <= n; i++)
        cin >> row[i];
    for(int i = 1; i <= n; i++) {
        ll cont = 1;
        int j = row[i];
        while(cont < 103 and j != i) {
            cont++;
            j = row[j]; 
        }
        ans[i] = cont;
        if(ans[i] % 2 == 0) ans[i] /= 2;
    }
    ll mult = ans[1];
    for(int i = 1; i <= n; i++) {
        if(ans[i] == 103) {
            cout << -1 << endl;
            return 0;
        }        
        mult = (mult*ans[i])/__gcd(mult,ans[i]); 
    }
    cout << mult << endl;

    return 0;
}

