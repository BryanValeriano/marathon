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
int s[T];
vector<int> v;

 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int zero = 0;

    for(int i = n-1; i >= 0; i--) cin >> s[i];
    
    for(int i = 0; i < n; i++) {
        if(!s[i]) zero++;
        else v.pb(zero), zero = 0;
    }

    reverse(v.begin(),v.end());

    int cool = zero;
    int tot = cool;
    int ans = (cool + (int)v.size());

    for(int i = 0; i < (int)v.size(); i++) {
        tot += v[i];
        ans = max(tot + (int)v.size() - (i+1), ans);
    }

    cout << ans << endl;
    return 0;
}

