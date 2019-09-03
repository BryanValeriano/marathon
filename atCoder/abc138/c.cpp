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

const int T = 55;
double v[T];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x;
    }

    sort(v,v+n);
    for(int i = 1; i < n; i++) v[i] = (v[i]+v[i-1])/2;
    cout << fixed << setprecision(5) << v[n-1] << endl;

    return 0;
}

