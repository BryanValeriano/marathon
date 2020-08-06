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
const int K = 25;
const int T = 1e7+1;
const int N = 4e5+3;
ll freq[2][T+3];
ll v[N], r[K];
int n;

ll mini(int op, int val, int k) {
    return max(0,(1<<(k+op))+(op?(1<<k):0)-val);
}

ll maxi(int op, int val, int k) {
    return max(0,(op?(1<<(k+2))-2-val:(1<<(k+1))-1-val));
}

int calc(int j, ll x, ll xx, ll y, ll yy, ll at, int i) {
    if(x > xx) swap(x,xx), swap(y,yy);
    ll a,b,c;
    a = b = c = 0;
    ll wtf = freq[at][j]-(j-1>=0?freq[at][j-1]:0);

    if(x <= T) {
        y = min(y,(ll)T-1);
        a = wtf*(freq[at][y]-(x-1>=0?freq[at][x-1]:0))-((x <= j and j <= y)?wtf:0);
    }
    if(!i) return a;

    if(xx <= T) {
        yy = min(yy,(ll)T-1);
        b = wtf*(freq[at][yy]-(xx-1>=0?freq[at][xx-1]:0))-((xx <= j and j <= yy)?wtf:0);
    }


    a = max(0ll,a); b = max(0ll,b); c = max(0ll,c);
    return (i?a+b-c:a);
}

int main() {
    ios_base::sync_with_stdio(false);
    int ans = 0;
    bool at = 1;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        freq[at][v[i]%(1<<K)]++;
    }

    for(int i = 1; i < T; i++) freq[at][i] += freq[at][i-1];
    //for(int i = 1; i <= (v[0]<<1); i <<= 1)
    //    if((v[0]<<1)&i) cout << "ok " << i << endl;

    for(int i = K-1; i >= 0; i--) {
        for(int j = 0; j < min(T,(1<<(i+1))); j++) {
            ll x = mini(0,j,i);
            ll xx = mini(1,j,i);
            ll y = maxi(0,j,i);
            ll yy = maxi(1,j,i);
            r[i] += calc(j,x,xx,y,yy,at,i);
        }
        r[i] >>= 1;
        memset(freq[!at],0,sizeof freq[!at]);
        for(int j = 0; j < n; j++) freq[!at][v[j]%(1<<i)]++;
        for(int j = 1; j <= min(T-1,(1<<(i+1))); j++)
            freq[!at][j] += freq[!at][j-1];
        at = !at;
    }

    for(int i = 0; i < K; i++) ans += (r[i]&1? (1<<i) : 0);//, cout << r[i] << endl;
    cout << ans << endl;

    return 0;
}
