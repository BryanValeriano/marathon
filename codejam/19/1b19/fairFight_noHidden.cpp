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

const int T = 110;
int a[T];
int b[T];
int n,k;

int solve() {
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int Ma = a[i];
        int Mb = b[i];
        for(int j = 0; i+j < n; j++) {
            Ma = max(Ma, a[i+j]);
            Mb = max(Mb, b[i+j]);
            if(abs(Ma - Mb) <= k) ans++;
        }
    }

    return ans;
}

void read() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        read();
        cout << "Case #" << ++cont <<": " << solve() << endl;
    }
    return 0;
}

