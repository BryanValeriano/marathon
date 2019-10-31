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
const int T = 1e4 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int x;
    int n = 0;
    while(cin >> x) {
        n++;
        v[n] = x;
        if(n&1) {
            nth_element(v+1,v+(n/2)+1,v+n+1);
            cout << v[(n/2)+1] << endl;
        } else {
            nth_element(v+1,v+(n/2),v+n+1);
            ll a = v[n/2];
            nth_element(v+1,v+(n/2)+1,v+n+1);
            ll b = v[(n/2)+1];
            cout << (a+b)/2 << endl;
        }
    }
    return 0;
}

