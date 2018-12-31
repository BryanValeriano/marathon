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
const int T = 60;
int n;
int v[T];
int ans[T];

void print() {
    for(int i = 0; i < 6; i++) {
        cout << ans[i];
        if(i+1 < 6) cout << " ";
    }
    cout << endl;
}

void solve(int atual, int ini) {
    if(atual == 6) { print(); return; }
    for(int i = ini; i <= atual + (n-6); i++) {
        ans[atual] = v[i];
        solve(atual+1, i+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while(n) {
        for(int i = 0; i < n; i++) cin >> v[i];
        solve(0,0);
        cin >> n;
        if(n) cout << endl;
    }

    return 0;
}

