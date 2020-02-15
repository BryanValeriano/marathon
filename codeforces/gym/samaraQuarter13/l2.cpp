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

vector<int> memo;
map<int, int> conv;
map<int, vector<int>> divsmemo;

vector<int> divs(int n) {
    try {
        return divsmemo.at(n);
    }
    catch (exception& e) {
        vector<int> ds;
        for (int i = 2;i * i <= n;i++) {
            if (n % i == 0) {
                ds.pb(i);
                if(i != n/i) ds.pb(n/i);
            }
        }
        ds.pb(1);
        return divsmemo[n] = ds;
    }
}

int solve(int n) {
    if (n == 1) return 1;
    int a = conv[n];
    if (memo[a] != -1) return memo[a];

    auto ds = divs(n);
    int ans = n / 2 + 1;

    for (int x : ds) {
        int y = solve(x);
        ans = min(ans, y * ((n / x) / 2 + 1));
    }
    return memo[a] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    memo.resize(n, -1);
    int next = 0;
    for (int x : divs(n)) conv[x] = next++;
    cout << solve(n) << endl;
    
    return 0;
}

