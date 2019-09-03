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

const int T = 2e5 + 3;
int v[T];
int n, t;

int f(ll x) {
    int ans = 0;
    for(ll i = 1; i <= n; i++) 
        if(x + i >= v[i] and x + i < T) ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> v[i];

    return 0;
}

