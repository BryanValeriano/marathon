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
const int T = 1e7 + 1;
bitset<T> v;
vector<int>ans;

void crivo() {
    for(int i = 2; i < T; i++) {
        if(!v.test(i)) {
            ans.pb(i);
            for(int j = i + i; j < T; j += i)
                v.set(j, 1);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    crivo();
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

