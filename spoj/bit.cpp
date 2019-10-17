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
    ll n;
    cin >> n;
    int cont = 0;
    while(n != 0) {
        cout << "Teste " << ++cont << endl;
        cout << n/50 << " ";
        n -= (n/50)*50ll;
        cout << n/10 << " ";
        n -= (n/10)*10ll;
        cout << (n/5) << " ";
        n -= (n/5)*5ll;
        cout << n/1 << endl;
        cin >> n;
        if(n) cout << endl;
    }

    
    
    return 0;
}

