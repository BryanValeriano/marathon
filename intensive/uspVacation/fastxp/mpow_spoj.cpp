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
const int MOD = 1e9 + 7;
int n, p;

typedef vector< vector<ll> > mat;

void print(mat m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

mat read() {
    mat m = mat(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> m[i][j];
    return m;
}

mat operator * (mat a, mat b) {
    mat m = mat(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                m[i][j] += (a[i][k] * b[k][j]) % MOD;
                m[i][j] %= MOD;
            }
        }
    }
    return m;
}

mat id() {
    mat m(n, vector<ll>(n,0));
    for(int i = 0; i < n; i++) m[i][i] = 1;
    return m;
}

mat expo(mat m) {
    mat ans = id();
    mat ele = m;
   
    while(p) {
        if(p & 1) ans = ans * ele;
        ele = ele * ele;
        p >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> p;
        mat m = read();
        m = expo(m);
        print(m);
    }
    return 0;
}

