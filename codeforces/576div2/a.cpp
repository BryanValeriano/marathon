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

const int T = 1e5 + 3; 
int v[T];
int n,a,b;

void check(int x) {
    for(int i = max(0,x-a); i <= min(n-1,x+b); i++) 
        if(i != x and v[i] < v[x]) return;
    cout << x+1 << endl;
    exit(0);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) check(i);
    return 0;
}

