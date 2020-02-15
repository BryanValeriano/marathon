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

const int T = 202;
int v[T];
int n;

bool find(int x, int op) {
    int f = (op == 0? 2 : n);

    for(int i = (x+1)%n; i != x; (++i) %= n) { 
        if(v[i] != f) return 0;
        f += (op == 0? 1 : -1);
    }

    return 1;
}

 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n;
        int start = 0;

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] == 1) start = i;
        }

        cout << (find(start,0) or find(start,1)? "YES" : "NO") << endl;

    }
    
    return 0;
}

