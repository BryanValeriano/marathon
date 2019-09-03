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
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int aux;
    for(int i = 0; i < m; i++) { cin >> aux; v[aux]++; }
    for(int i = 101; i >= 1; i--) {
        int p = 0;
        for(int j = 0; j < T; j++) {
            if(v[j] != 0) p += (v[j] / i);
        }
        if(p >= n) { cout << i << endl; return 0; }
    }
    cout << 0 << endl;
    return 0;
}

