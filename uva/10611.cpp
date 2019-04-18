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

set<int> v;
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int x;

    for(int i = 0; i < n; i++) cin >> x, v.insert(x);

    int q; cin >> q;

    while(q--) {
        cin >> x; 
        auto it = v.lower_bound(x); 
        if(it == v.end()) it--;
        while(it != v.cend() and *it >= x) it--;
        if(it == v.cend()) cout << 'X';
        else cout << *it;
        cout << " ";

        it = v.upper_bound(x);
        while(it != v.end() and *it <= x) it++;
        if(it == v.end()) cout << 'X'; 
        else cout << *it;
        cout << endl;

    
    }
    
    return 0;
}

