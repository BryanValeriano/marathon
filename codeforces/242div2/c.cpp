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

const int T = 1e6 + 5;
int n;
ll col[T];

void colunas() {
    for(int i = 1; i <= n; i++) {
        int qtd = n/i;
        if(qtd&1) {
            col[(n%i)+1]++;
            col[i]--;
        } else {
            col[1]++;
            col[(n%i)+1]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    colunas();
    ll x;
    ll ans;
    cin >> ans;

    for(int i = 1; i < n; i++) {
        cin >> x;
        ans ^= x;
    }

    for(int i = 1; i <= n; i++) col[i] += col[i-1];

    for(int i = 0; i < n; i++) 
        if((col[i]&1)) ans ^= i;

    cout << ans << endl;

    return 0;
}

