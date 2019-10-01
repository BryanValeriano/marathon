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

int col(ll x) {
    if(x == 1) return 1;
    if(x&1) return col(3*x+1) + 1;
    else return col(x/2) + 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int ans = 0;
    int qtd = 0;
    for(int i = 1; i <= 1000000; i++) {
        int x = col(i);
        if(x > qtd) qtd = x, ans = i;
    }
    cout << ans << " " << qtd << endl;
    return 0;
}

