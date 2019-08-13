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
const int T = 1e5 + 2;
ll v[T];
ll sum;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int x;

    for(int i = 0; i < n; i++) cin >> v[i], sum += v[i];

    if(sum&1) { cout << "NO" << endl; return 0; }

    bool ok = 1;
    for(int i = 0; i < n; i++) ok &= v[i] <= sum-v[i];

    cout << (ok? "YES" : "NO") << endl;

    return 0;
}

