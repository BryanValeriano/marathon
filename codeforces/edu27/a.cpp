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
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n*2; i++) cin >> v[i];

    sort(v, v+2*n,greater<int>());

    bool ok = true;

    int j = n;
    for(int i = n-1; i >= 0; i--) ok &= v[i] > v[j++];

    cout << (ok? "YES" : "NO") << endl;

    return 0;
}

