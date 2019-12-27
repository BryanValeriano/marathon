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
const int T = 1e3 + 5;

int n,m,d;
int c[T];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> d;
    for(int i = 0; i < m; i++) cin >> c[i];

    vector<int> ans;
    int at = 0;

    while(at < m) {
        for(int i = 0; i < c[at]; i++) ans.pb(at+1);
        at++;
    }

    at = m-1;
    int sz = 0;
    int sobra = n-ans.size();
    while(ans.size() < n) ans.pb(0);

    while(ans[max(0,n-d)] == 0) {
        if(at == -1 or d == 1) {
            cout << "NO" << endl;
            return 0;
        }

        int ponta = ans.size() - c[at] - sobra;
        ans.insert(ans.begin() + ponta, 0);

        sz++;
        if(sz == d-1) sobra += sz+c[at], sz = 0, at--;
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;


    return 0;
}

