#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 4;
int n,t;
ll v[T];
ll acum[T];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    int maxi = -1;
    int lucro = 0;
    int qtd = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = n-1; i >= 0; i--) {
        if(v[i] > maxi) maxi = v[i];
        if(maxi-v[i] > lucro) lucro = maxi-v[i], qtd = 1;
        else if(maxi-v[i] == lucro) qtd++;
    }
    cout << qtd << endl;
    return 0;
}

