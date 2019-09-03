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

int n,at;
const int T = 110;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> at;

    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = 0;
    at--;
    if(v[at]) ans++;

    for(int i = 1; i <= 100; i++) {
        if(at-i >= 0 and at+i < n) if(v[at-i] == 1 and v[at+i] == 1) ans+= 2;
        if(at-i < 0 and at+i < n) if(v[at+i] == 1) ans++;
        if(at-i >= 0 and at+i >= n) if(v[at-i] == 1) ans++;
    }

    cout << ans << endl;

    return 0;
}

