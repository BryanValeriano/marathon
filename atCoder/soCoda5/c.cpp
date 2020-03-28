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
const int T = 2e5 + 4;

ll v[T];
ll suml1;
ll suml2;
ll sumr1;
ll sumr2;

ll calc() {
    return max({suml1,suml2,sumr1,sumr2})-min({suml1,suml2,sumr1,sumr2});
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 0;
    int r = n-1;
    int m = n-3;

    suml1 = v[l];
    suml2 = 0;
    sumr1 = v[r-1];
    sumr2 = v[r];

    for(int i = 1; i <= m; i++) suml2 += v[i];
    while(l+1 < m and abs(suml2-suml1) >= abs((suml2-v[l+1])-(suml1+v[l+1]))) {
        suml2 -= v[l+1];
        suml1 += v[l+1];
        l++;
    }

    ll ans = calc();
    m--;

    while(m > 0) {
        suml2 -= v[m+1];
        sumr1 += v[m+1];

        while(r-1 > m+1 and abs((sumr1-v[r-1])-(sumr2+v[r-1])) <= abs(sumr1-sumr2)) {
            sumr1 -= v[r-1];
            sumr2 += v[r-1];
            r--;
        }

        while(l > 0 and ((abs((suml1-v[l])-(suml2+v[l])) <= abs(suml1-suml2)) or l == m)) {
            suml1 -= v[l];
            suml2 += v[l];
            l--;
        }

        ans = min(ans,calc());
        m--;
    }

    cout << ans << endl;

    return 0;
}

