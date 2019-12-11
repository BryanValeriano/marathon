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

vector<int> v(5);
vector<int> a(5);
vector<int> x(5);

int calc(int last) {
    if(last > 3) return 0;

    int at = last;
    while(v[at+1] == v[at]+1) at++;

    int f = at + 1;

    for(int i = 0; i < 4; i++)
        if(52-a[i] + v[at] < 52) f++;

    int ans = (52-f)*(at-last+1);
    return ans + calc(at+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    v[4] = 55;
    for(int i = 0; i < 4; i++) cin >> a[i];
    int ans = INF;

    for(int i = 1; i < 53; i++) {
        v[0] = i;
        for(int j = i+1; j < 53; j++) {
            v[1] = j;
            for(int k = j+1; k < 53; k++) {
                v[2] = k;
                for(int p = k+1; p < 53; p++) {
                    v[3] = p;
                    int z = calc(0);
                    if(ans > z) ans = z, x = v;
                }
            }
        }
    }

    cout << ans << endl;
    for(int i = 0; i < 4; i++) cout << x[i] << " ";
    cout << endl;
    return 0;
}

