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

const int T = 1000;

bool ok(int a, int b, int c) {
    if(a < b) swap(a,b);
    if(a < c) swap(a,c);
    return (a*a == b*b + c*c);
}

int main() {
    ios_base::sync_with_stdio(false);

    int ans = 0;
    int best = 0;

    for(int i = 12; i <= T; i++) {
        int x = 0;
        for(int j = 1; j <= i-2; j++) {
            for(int p = j+1; p <= i-j-1; p++) {
                int k = i-j-p;
                if(k < p) break;
                if(ok(j,p,k)) x++;
            }
        }
        if(x > best) best = x, ans = i;
    }

    cout << ans << " " << best << endl;

    return 0;
}

