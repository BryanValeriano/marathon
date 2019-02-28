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

ll ele() {
    ll ans = 2;
    for(int i = 2; i <= 32; i++) 
        ans *= 2;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    for(int i = 0; i < 1000; i++) 
        cout << ele()-1 << endl;
    cout << 0 << endl;
    return 0;
}

