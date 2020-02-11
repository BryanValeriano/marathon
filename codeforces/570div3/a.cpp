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

int r(int x) {
    int ans = 0;

    while(x) {
        ans += x%10;
        x /= 10;
    }
    
    return (!(ans%4));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int x; cin >> x;
    while(!r(x)) x++;
    cout << x << endl;
    return 0;
}

