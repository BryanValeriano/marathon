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
    int a, b;
    while(cin >> a) {
        cin >> b;
        string ans;
        if(__gcd(a,b) == 1) ans = "Good ";
        else ans = "Bad ";
        ans += "Choice";
        cout << setw(10) << right << a;
        cout << setw(10) << right << b;
        cout << "    ";
        cout << ans << endl << endl;
    }
    return 0;
}

