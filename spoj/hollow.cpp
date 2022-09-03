#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;
int vis[T];
int lastMod[T];

int main() {
    ios_base::sync_with_stdio(false);
    int c,n;
    cin >> c >> n;
    int vez = 0;

    while(c && n) {
        ++vez;
        ll sum = 0;
        int a,b;
        a = b = 0;

        vis[0] = vez;
        lastMod[0] = 0;

        for(int i = 1; i <= n; i++) {
            ll x; cin >> x;

            sum += x;
            sum %= c;

            if(x%c == 0) a = b = i;
            else if(vis[sum] == vez) {
                a = lastMod[sum]+1;
                b = i;
            }
            vis[sum] = vez;
            lastMod[sum] = i;
        }

        if(a)
            for(int i = a; i <= b; i++)
                cout << i << (i+1 <= b? ' ' : '\n');
        else cout << "no sweets\n";

        cin >> c >> n;
    }
    return 0;
}

