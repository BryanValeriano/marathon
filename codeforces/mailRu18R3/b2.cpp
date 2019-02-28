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

const int T = 1010;
bool vis[T][T];
ll n, k;
ll ans;

void pre() {
    for(ll i = 1; i <= k; i++) {
        for(ll j = 1; j <= k; j++) {
            if(!vis[i][j] and (i*i + j*j) % k == 0) {
                ll tmp = 2;
                ans += min(n/i, n/j);
                ll I = (n-i)/k;
                ll J = (n-j)/k;
                ans += (I*J);
                //ans += min(I, J);
                while(tmp * i <= k and tmp * j <= k) {
                    vis[tmp*i][tmp*j] = true;
                    ll II = (n-(tmp*i))/k;
                    ll JJ = (n-(tmp*j))/k;
                    ans += (II*JJ);
                    //ans += min(II,JJ);
                    tmp++;
                }
                cout << i << " " << j << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    pre();
    cout << ans << endl;
    return 0;
}

