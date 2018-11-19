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
const int T = 12;
int n, s;
int v[T];

int limpa(int x, int sum) {
    while(true) {
        int y = -INF;
        int pos = -INF;
        for(int i = 0; i < 10; i++) 
            if(x & 1<<i and sum - v[i] >= s) 
                if(y < v[i]) { y = v[i]; pos = i; }
        if(y == -INF) break;
        else { x &= 0<<pos; sum -= v[pos]; }
    }
    return x;
}

int brute(int sum, int mask, int iter) {
    if(sum == s) return __builtin_popcount(mask);
    if(sum > s) { mask = limpa(mask, sum); return __builtin_popcount(mask); }
    if(iter == n) return 0;

    return max(brute(sum + v[iter], mask | 1<<iter, iter+1), brute(sum, mask, iter+1)); 
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> s;
        for(int i = 0; i < n; i++) 
            cin >> v[i];
        cout << brute(0, 0, 0) << endl;
    }
    return 0;
}

