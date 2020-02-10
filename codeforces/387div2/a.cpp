#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ans = INF;
    int a = 1;
    int b = n;

    for(int i = 1; i <= n/2; i++) {
        if(n%i) continue;
        int x = n/i;
        if(x >= i and x-i < ans) ans = x-i, a = i, b = x;
    }

    cout << a << " " << b << endl;

    return 0;
}

