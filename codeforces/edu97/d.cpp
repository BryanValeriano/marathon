#include <bits/stdc++.h>
using namespace std;

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
    int tc; cin >> tc;

    while(tc--) {
        int n; cin >> n;
        int at, last;
        int ans = 0, h = 0;

        ii fat;
        queue<ii> lista;
        lista.emplace(1,0);
        last = INF;

        cin >> at;
        n--;

        while(n--) {
            cin >> at;
            if(at < last) {
                fat = lista.front();
                lista.pop();
                h = fat.se+1;
            }
            lista.emplace(at,h);
            ans = max(ans,h);
            last = at;
        }
        cout << ans << endl;
    }
    return 0;
}

