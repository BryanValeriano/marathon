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
    int n,a,b;
    cin >> n >> a >> b;
    int ans = -1;
    for(int i = 1; i < n; i++) 
        if(i <= a and (n-i) <= b) 
            ans = max(ans,min(a/i,b/(n-i)));
    cout << ans << endl; 
    return 0;
}

