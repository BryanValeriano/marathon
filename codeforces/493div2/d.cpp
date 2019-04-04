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

const int T = 100;
ll f[T];

ll fi(ll x) {
    if(f[x] != 0) return f[x];
    return fi(x-1) + fi(x-2) + fi(x-3) + fi(x-4);
}

int main() {
    ios::sync_with_stdio(false);
    f[0] = f[1] = f[2] = f[3] = 1;
    for(int i = 2; i <= 10; i++) 
        cout << fi(i) << endl;
    return 0;
}

