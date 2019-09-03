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
ll m,d,a,b;

bool isMagic(ll x) {
    int casa = log(x)/log(10) + 1;
    int atual;
    bool flag = true;
    while(x) {
        atual = x%10;
        if(atual == d and casa & 1) return false;
        if(!(casa & 1)) flag &= (atual == d);
        x /= 10;
        casa--;
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> d >> a >> b;
    int x = 0;
    for(; a <= b; a++) if(!(a % m))x += isMagic(a);
    cout << x << endl;
    return 0;
}

