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

int n,m;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m; 
    
    int j = 0;
    for(int i = 1; i <= n; i++) {
        cout << 1 << endl << i+j << " " << i+j << endl;
        j += 2;
    }
    
    return 0;
}

