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
    int a,b,c;
    cin >> a >> b >> c;
    while(a != 0 or b != 0 or c != 0) {
        a -= 7;
        b -= 7;
        a = a*b;
        if(c == 1) a++;
        a /= 2;
        cout << a << endl;
        cin >> a >> b >> c;
    }
    return 0;
}

