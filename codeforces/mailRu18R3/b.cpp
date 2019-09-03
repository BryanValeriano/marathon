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

const ll T = 1010;
bool vis[T+2][T+2];
ll n, k;
ll ans;

void doit() {
    for(ll i = 1; i <= min(T,n); i++) 
        for(ll j = 1; j <= min(T,n); j++) 
            if(!vis[i][j] and (i*i + j*j) % k == 0) {
                cout << i << " " << j << endl;
                ans += 1;
            }
}

void pre() {
    for(ll i = 1; i < T; i++) {
        for(ll j = 1; j < T; j++) {
            if(!vis[i][j] and (i*i + j*j) % k == 0) {
                ll tmp = 2;
                while(tmp * i < T and tmp * j < T) {
                    vis[tmp*i][tmp*j] = true;
                    tmp++;
                }
                tmp = k;
                while(tmp + i < T) {
                    vis[tmp + i][j] = true;
                    tmp += k;
                } 
                tmp = k;
                while(tmp + j < T) {
                    vis[i][tmp + j] = true;
                    tmp += k;
                } 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(k == 1) { cout << n*n << endl; return 0; }
    //pre();
    doit();
    cout << ans << endl;
    return 0;
}

