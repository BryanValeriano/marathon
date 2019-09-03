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
    ll x; cin >> x;
    int cont = 0;
    int tmp;
    while(x > 0) {
        tmp = x%10;
        if(tmp == 4 or tmp == 7) cont++;
        x /= 10;
    }
    if(cont == 4 or cont == 7 or cont == 14 or cont == 17)
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

