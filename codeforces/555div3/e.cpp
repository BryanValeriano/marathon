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

const int T = 2e5 + 10;
int v[T];
int ans[T];
multiset<int> bag;

int main() {
    ios::sync_with_stdio(false);
    int n, x; cin >> n; 
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> x, bag.insert(x); 

    for(int i = 0; i < n; i++) {
        multiset<int>::iterator a = bag.lower_bound(n-v[i]);
        while(a == bag.end()) a--;
        multiset<int>::iterator b = bag.lower_bound(0);

        if((v[i] + *a) % n < (v[i] + *b) % n) {
            ans[i] = *a + v[i];
            bag.erase(a);
        } else {
            ans[i] = *b + v[i];
            bag.erase(b);
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i] % n << " ";
    cout << endl;

    return 0;
}

