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
const int T = 202;
int xi[T], yi[T], xf[T], yf[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    //if(n==1 and m==1) { cout << 0 << endl; return 0; }
    string ans;
    for(int i = 0; i < n-1; i++) ans += 'U';
    for(int i = 0; i < m-1; i++) ans += 'L';
    for(int i = 0; i < n; i++) {
        if(i) ans += 'D';
        for(int j = 0; j < m-1; j++) ans += (i&1? 'L' : 'R');
    }
    cout << ans.size() << endl << ans << endl;
    return 0;
}

