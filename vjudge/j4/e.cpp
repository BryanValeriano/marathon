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
const int T = 102;
ll a[T][T], b[T][T];
ll sumA[T], sumB[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            sumA[j] += a[i][j];
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> b[i][j];
            sumB[i] += b[i][j];
        }

    ll ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                ans += a[i][k]*b[k][j];

    int q;
    cin >> q;

    while(q--) {
        char x;
        int i,j,d;
        cin >> x >> i >> j >> d;
        if(x == 'A') {
            ans -= a[i][j]*sumB[j];
            sumA[j] -= a[i][j];
            a[i][j] = d;
            ans += a[i][j]*sumB[j];
            sumA[j] += a[i][j];
        } else {
            ans -= b[i][j]*sumA[i];
            sumB[i] -= b[i][j];
            b[i][j] = d;
            ans += b[i][j]*sumA[i];
            sumB[i] += b[i][j];
        }
        cout << ans << endl;
    }

    return 0;
}

