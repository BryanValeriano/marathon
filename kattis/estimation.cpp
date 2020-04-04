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
const ll INF = 1e15;
const int N = 4e4 + 5;
const int LOGN = log2(N);
const int T = 2e3 + 2;
const int K = 27;

ll bit[2][N+2];
ll dp[T][K];
ll pre[T][T];
ll v[T];
int n, k;

void update(ll val, int pos, int id) {
    for(; pos < N; pos += pos&(-pos)) bit[id][pos] += val;
}

ll rsq(int pos, int id) {
    ll sum = 0;
    for(; pos; pos -= pos&(-pos)) sum += bit[id][pos];
    return sum;
}

ll query(int ini, int fim, int id) {
    return rsq(fim,id) - (ini == 1? 0 : rsq(ini-1,id));
}

int search(int x) {
    int sum = 0;
    int pos = 0;
    for(int i = LOGN; i >= 0; i--) {
        if(pos + (1<<i) < N and sum+bit[1][pos+(1<<i)] < x) {
            sum += bit[1][pos+(1<<i)];
            pos += (1 << i);
        }
    }

    return pos+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] += (1e4 + 2);
    }

    for(int i = 0; i < n; i++) {
        ll sum = 0;
        memset(bit[0], 0, sizeof bit[0]);
        memset(bit[1], 0, sizeof bit[1]);
        for(int j = i; j < n; j++) {
            update(v[j],v[j],0);
            update(1,v[j],1);
            sum += v[j];
            int x = ((j-i+1)>>1)+((j-i+1)&1);
            ll est = search(x);
            ll menor = query(1,est,1)*est-query(1,est,0);
            ll maior = query(est+1,N,0)-est*query(est+1,N,1);
            pre[i][j] = maior+menor;
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = INF;

    for(int i = 0; i < n; i++) dp[i][1] = pre[0][i];

    for(int p = 2; p <= k; p++)
        for(int j = 1; j < n; j++)
            for(int i = 0; i < j; i++)
                dp[j][p] = min(dp[j][p], dp[i][p-1] + pre[i+1][j]);

    cout << dp[n-1][k] << endl;
    return 0;
}

