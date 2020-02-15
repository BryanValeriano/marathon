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

    int n; cin >>n;

    vector<int> div;
    for(int i = 1; i*i <= n; i++) {
        if(n%i == 0) div.pb(i);
        if(i != n/i) div.pb(n/i);
    }

    int minp = n;
    for(auto at:div) {
        int qtdP = (at/2)+1;
        int qtdG = ((n/at)/2)+1;
        minp = min(minp, qtdP * qtdG);
    }
    cout <<minp <<endl;

    
    return 0;
}

