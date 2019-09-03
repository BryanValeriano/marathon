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
const int T = 20;
const int N = 2e4;
int n, m;
ll barras[T];
ll pesos[T];
set<ll> equals;

void brute(int i, ll suml, ll sumr) {
    if(suml == sumr) equals.insert(suml + sumr);
    if(i == m) return;

    brute(i+1, suml + pesos[i], sumr);
    brute(i+1, suml, sumr + pesos[i]);
    brute(i+1, suml, sumr);
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> barras[i];
    for(int i = 0; i < m; i++) cin >> pesos[i];
    brute(0,0,0);

    set<ll>ans;
    for(int i = 0; i < n; i++)
        for(auto x : equals)
            ans.insert(barras[i] + x);

    for(auto x : ans) cout << x << endl;
    return 0;
}

