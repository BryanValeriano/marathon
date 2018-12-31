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
const int T = 25;
int n, gol;
int v[T];

void read() {
    cin >> gol;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
}

bool solve(int atual, int sum) {
    if(sum == gol) return true;
    if(atual == n or sum > gol) return false;
    
    return solve(atual+1, sum + v[atual]) or solve(atual+1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        read();    
        cout << (solve(0,0)? "YES" : "NO") << endl;;
    }
    return 0;
}

