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
const int T = 1e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v, v+n);
    if(v[1] - v[0] >= v[n-1] - v[n-2]) cout << v[n-1] - v[1];
    else cout << v[n-2] - v[0];
    cout << endl;

    return 0;
}

