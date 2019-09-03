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

ll lcm(ll a, ll b) {
    return (a*b) / __gcd(a,b);
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int n,m,d;
    int a[5];

    while(tc--) {
        cin >> n >> m >> a[0] >> d;
        for(int i = 1; i <= 4; i++) a[i] = a[i-1] + d;

        int ans = 0;
        for(int i = 0; i <= 4; i++) 
            ans += (m/a[i]) - ((n-1)/a[i]);

        for(int i = 0; i <= 4; i++)
            for(int j = i+1; j <= 4; j++) 
                ans -= (m/lcm(a[i],a[j])) - ((n-1)/lcm(a[i],a[j]));
            

        for(int i = 0; i <= 4; i++)
            for(int j = i+1; j <= 4; j++)
                for(int k = j+1; k <= 4; k++) {
                    int top = m/lcm(a[i], lcm(a[j],a[k]));
                    int bot = (n-1)/lcm(a[i], lcm(a[j],a[k]));
                    ans += (top - bot);
                }

        for(int i = 0; i <= 4; i++)
            for(int j = i+1; j <= 4; j++)
                for(int k = j+1; k <= 4; k++)
                    for(int p = k+1; p <= 4; p++) {
                        int top = m/lcm(a[i], lcm(a[j], lcm(a[k],a[p])));
                        int bot = (n-1)/lcm(a[i], lcm(a[j], lcm(a[k],a[p])));
                        ans -= (top - bot);
                    }


        int top = m/lcm(a[0], lcm(a[1], lcm(a[2], lcm(a[3],a[4]))));
        int bot = (n-1)/lcm(a[0], lcm(a[1], lcm(a[2], lcm(a[3],a[4]))));
        ans += (top - bot);

        cout << (m-n+1)- ans << endl;
    }
    return 0;
}

