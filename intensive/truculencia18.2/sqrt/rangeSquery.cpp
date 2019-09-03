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
const int T = 1e5 + 1000;
const int N = sqrt(T);
int v[T];
ll bucket[N];

void update(int ind, int val) {
    bucket[ind/N] -= v[ind];
    v[ind] = val;
    bucket[ind/N] += v[ind];
}

ll query(int l, int r) {
    ll ans = 0;
    int primeiro = l/N;
    int segundo = r/N;

    while(l/N <= primeiro and l <= r) 
        ans += v[l++];

    while(l/N < segundo) { 
        ans += bucket[l/N];
        l += N;
    }

    while(l <= r) ans += v[l++];

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        bucket[i/N] += v[i];
    }
    char oper;
    int a,b;
    while(q--) {
        cin >> oper >> a >> b;
        if(oper == '?') cout << query(a,b) << endl;
        else update(a,b);
    }
    return 0;
}

