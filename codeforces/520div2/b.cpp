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
    ios_base::sync_with_stdio(false);
    int x; cin >> x;
    int n = x;
    int ans = 1;
    int qtd = 0;

    for(int i = 2; i*i <= x; i++) {
        int q = 0;
        while(x % i == 0) {
            q++;
            x /= i;
            if(ans % i) ans *= i;
        }
        qtd = max(q,qtd);
    }

    if(x > 1) ans *= x, qtd = max(qtd,1);

    int log = 1;
    while(log < qtd) log *= 2;
    if(pow(ans,log) != n) log *= 2;
    
    cout << ans << " " << log2(log) << endl; 
    
    return 0;
}

