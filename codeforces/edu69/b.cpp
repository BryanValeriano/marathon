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

const int T = 2e5 + 5;
int v[T];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int top = 0;
    int pos = 0;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i] > top) top = v[i], pos = i;
    }

    bool ok = 1;

    for(int i = 1; i <= pos; i++) 
        ok &= v[i] > v[i-1];

    for(int i = n; i >= pos; i--)
        ok &= v[i] > v[i+1];

    cout << (ok? "YES" : "NO") << endl;
    return 0;
}

