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
const int T = 12;
int m[T][T];
int l[T], c[T],d1,d2;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
            l[i] += m[i][j];
            c[j] += m[i][j];
            if(i==j) d1 += m[i][j];
            if(i+j==n-1) d2 += m[i][j];
        }
    }

    bool ok = 1;
    for(int i = 1; i < n; i++)
        ok &= ((l[i]==l[i-1]) & (c[i]==c[i-1]) & (l[i] == c[i]));
    ok &= ((l[0] == d1) & (d1 == d2));

    cout << (ok?l[0]:-1) << endl;
    return 0;
}

