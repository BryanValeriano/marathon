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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int maxi = 0;
    for(int i = 0; i*a <= n; i++) {
        for(int j = 0; j*b + i*a <= n; j++) {
            int x = (n - (j*b + i*a))/c;
            if(i*a + j*b + x*c == n and x + i + j > maxi) maxi = x + i + j;
        }
    }
    cout << maxi << endl;
    return 0;
}

