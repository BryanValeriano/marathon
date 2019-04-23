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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int i = 0;

    if(a >= c) { cout << a << endl; return 0; }

    while(a != c) {
        a = min(a+b, c);
        c = max(c-d, a);
    }

    cout << a << endl;

    return 0;
}

