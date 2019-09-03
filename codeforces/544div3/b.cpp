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
    int n,k;
    cin >> n >> k;
    map<int,int> v;
    int x;
    int zeros = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if((x%k) == 0) zeros++;
        else v[x%k]++;
    }
    ans += zeros / 2;

    for(auto i : v) {
        if(v.count(k-i.fi)) {
            if(i.fi == k-i.fi) ans += v[i.fi]/2;
            else ans += min(v[i.fi], v[k-i.fi]);
            v[k-i.fi] = 0;
            v[i.fi] = 0;
        }
    }
    cout << ans*2 << endl;

    return 0;
}

