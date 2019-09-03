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
    ios::sync_with_stdio(false);
    int n,l,r;
    cin >> n >> l >> r;

    ll mini = 0;
    ll maxi = 0;

    int lim = n-l+1;
    ll at = 1;

    for(int i = 1; i <= n; i++) {
        mini += at;
        if(i >= lim) at *= 2; 
    }

    at = 1;
    for(int i = 1; i <= n; i++) {
        maxi += at;
        if(i < r) at*=2;
    }

    cout << mini << " " << maxi << endl;

    return 0;
}

