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

bool top(int x) {
    return (v[x] > v[x-1] and v[x] > v[x+1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,k; cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> v[i];
        int picos = 0;
        int maxi = 0;
        int l = 1;

        for(int i = 2; i < k; i++)
            if(top(i-1)) picos++;

        maxi = picos;

        for(int i = k; i < n; i++) {
            if(top(i-k+1)) picos--;
            if(top(i-1)) picos++;
            if(picos > maxi) {
                maxi = picos;
                l = i-k+2;
            }
        }

        cout << maxi+1 << " " << l << endl;
    }
    return 0;
}

