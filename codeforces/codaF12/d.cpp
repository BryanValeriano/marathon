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
const int T = 102;
const int N = 12;
int dp[T][(1<<N)];
int choose[T][(1<<N)];
int primes[12] = {1,2,3,5,7,11,13,17,19,23,29,31};
int a[T];
int n;

int best(int id, int at) {
    int x = primes[id];
    int y = x;
    x *= (a[at]/primes[id]);
    x = max(x,primes[id]);
    y *= ((a[at]/primes[id])+1);
    return (abs(x-a[at]) <= abs(y-a[at])? x : y);
}

void build(int at, int mask) {
    if(at >= n) { cout << endl; return; }
    cout << best(choose[at][mask],at) << " ";
    build(at+1,mask|(1<<choose[at][mask]));
}

int solve(int at, int mask) {
    if(at >= n) return 0;
    int &r = dp[at][mask];
    if(r != -1) return dp[at][mask];
    r = INF;

    for(int i = 0; i < 12; i++) {
        if(mask & (1<<i)) continue;
        int x = a[at]%primes[i];
        int y = (primes[i] <= a[at]? primes[i]-x : x);
        int l = solve(at+1,mask|(1<<i)) + min(x,y);
        if(l < r) {
            r = l;
            choose[at][mask] = i;
        }
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    solve(0,0);
    build(0,0);
    return 0;
}

