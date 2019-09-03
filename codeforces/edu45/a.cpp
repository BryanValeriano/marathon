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
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    ll a,b; cin >> a >> b;
    ll cust1 = 0;
    ll cust2 = 0;
    ll cust3 = 0;
    ll cust4 = 0;

    //adicionar para dar um multiplo de m
    if(n % m != 0 and n > m) {
        ll tot = n/m;
        tot++;
        cust1 = (tot*m - n) * a;
    } else cust1 = INF;
    
    //retirar para dar um multiplo de m
    if(n % m != 0 and n > m) {
        cust2 = (n % m) * b;
    } else cust2 = INF;
    
    //construir ate dar m
    if(n < m) {
        cust3 = (m - n) * a;
    } else cust3 = INF;

    //corner
    if(n % m == 0) cust1 = 0;
    //tirar tudo
    cust4 = n * b;


    cout << min({cust1, cust2,cust3,cust4}) << endl;

    return 0;
}

