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
const int T = 2e5+5;
int v[T];
int maxi = 0;

int main() {
    ios_base::sync_with_stdio(false);
    int n,x; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] > maxi) maxi = v[i];
    }

    maxi = maxi&1;
    int ok = 0;

    for(int i = 1; i < n; i++) {
        if((v[i-1]&1) == (v[i]&1)) ok++;
        else if(ok&1 && ((v[i-1]&1) != maxi)) {
            cout << "NO" << endl;
            return 0;
        } else ok = 0;
    }
    
    cout << "YES" << endl;
    return 0;
}
