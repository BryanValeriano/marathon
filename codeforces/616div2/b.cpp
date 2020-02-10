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
const int T = 3e5 + 5;

bool dir[T];
bool esq[T];
int v[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n;

        dir[n+1] = esq[0] = 1;
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
            esq[i] = ((v[i] >= i-1) & esq[i-1]);
        }

        for(int i = n; i >= 0; i--) dir[i] = ((v[i] >= n-i) & dir[i+1]);

        //for(int i = 1; i <= n; i++) cout << esq[i];
        //cout << endl;
        //for(int i = 1; i <= n; i++) cout << dir[i];
        //cout << endl;

        bool flag = 0;

        for(int i = 1; i <= n; i++) {
            if(esq[i] and dir[i]) {
                cout << "Yes" << endl;
                flag = 1;
                break;
            }
        }

        if(!flag) cout << "No" << endl;

    }
    return 0;
}

