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
    double n,k,t;
    cin >> n >> k >> t;
    t = n*k*(t/100);
    t = (int)t;

    for(int i = 0; i < n; i++)  {
        cout << min(t,k) << " ";
        t -= min(t,k);
    }
    cout << endl;
    return 0;
}

