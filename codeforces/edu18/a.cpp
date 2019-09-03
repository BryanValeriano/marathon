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
const ll INF = 5000000000000000000LL;

const int T = 2e5 + 10;
ll v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v, v+n);
    ll mini = INF;
    int qtd = 0;

    for(int i = 1; i < n; i++) {
        if(v[i] - v[i-1] < mini) {
            mini = v[i] - v[i-1];
            qtd = 1;
        }
        else if(v[i] - v[i-1] == mini) qtd++;
    }

    cout << mini << " " << qtd << endl;

    return 0;
}

