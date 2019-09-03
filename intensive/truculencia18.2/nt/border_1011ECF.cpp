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

const int T = 1e5 + 10;
vector<int> ans;
bitset<T> crivo;
set<int> v;
int k;

void explode() {
    vector<int> tmp1;
    set<int> tmp2;
    int sum = 0;
    for(int i : v) tmp1.pb(i);
    for(int i = 0; i < tmp1.size(); i++) {
        sum = tmp1[i];
        for(int j = i+1; j < tmp1.size(); j++) {
            sum = __gcd(sum,tmp1[j]);
            tmp2.insert(sum);
        }
    }
    for(int i : tmp2) v.insert(__gcd(i,k));
}

void gen() {
    for(int i : v) {
        if(crivo[i]) continue;
        if(i == 0) { crivo[i] = 0; continue; }
        for(int j = i; j <= k; j += i) crivo[j] = true; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> x;
        x = x % k;
        v.insert(__gcd(x,k));
    }
    explode();
    gen();
    if(crivo[k]) ans.pb(0);
    for(int i = 1; i < k; i++) if(crivo[i]) ans.pb(i);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

