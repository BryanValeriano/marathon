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

int main() {
    ios::sync_with_stdio(false);
    int n, a, b; 
    int va = -1;
    int vb = -1;
    cin >> n >> a >> b;
    for(int i = 0; i*a <= n; i++) {
        int j = (n - (i*a))/b;
        if(i*a + j*b == n) {
            va = i; vb = j;
            break;
        }
    }
    if(va == -1) { cout << -1 << endl; return 0; }

    int i;
    for(i = 1; i <= va*a; i++) { 
        if(i % a == 0) cout << i - a + 1 << " ";
        else cout << i+1 << " ";
    }
    for(i; i <= n; i++) {
        if((i - va*a) % b == 0) cout << i - b + 1 << " ";
        else cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}

