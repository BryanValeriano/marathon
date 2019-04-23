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

int main() {
    ios::sync_with_stdio(false);
    int x;
    int sum = 0;

    for(int i = 0; i < 5; i++) cin >> x, v[x]++, sum += x;

    int ans = 0;

    for(int i = 100; i >= 0; i--) {
        if(v[i] >= 3) ans = max(ans, i*3);
        if(v[i] >= 2) ans = max(ans, i*2);
    }
        
    cout << sum - ans << endl;

    return 0;
}

