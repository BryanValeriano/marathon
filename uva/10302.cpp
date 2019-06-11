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

const int T = 5e4 + 3;
ll v[T];

int main() {
    ios::sync_with_stdio(false);
    v[1] = 1; 
    for(ll i = 2; i < T; i++) 
        v[i] = v[i-1] + i*i*i;

    int x;
    while(cin >> x) cout << v[x] << endl;

    return 0;
}

