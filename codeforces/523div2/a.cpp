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
    ll n, s; cin >> n >> s;
    if(n >= s) {
        cout << 1 << endl;
        return 0;
    }
    ll cont = s/n;
    if(s%n!=0)cont++;
    cout << cont << endl;

    return 0;
}

