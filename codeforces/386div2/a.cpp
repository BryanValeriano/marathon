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
    int mini = min({a, b/2, c/4});
    cout << mini + mini*2 + mini*4 << endl;
    return 0;
}

