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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 3;
set<int> bag;
int v[T];
bool error[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = 1;
    for(int i = 0; i < k; i++) bag.insert(v[i]);

    int wat = 1;
    int taw = 0;
    bool ok = 0;

    while(wat < n) {
        if(v[wat] < v[wat-1]) taw = wat;
        if(wat-taw+1 >= k) error[wat] = 1;
        wat++;
    }

    if(error[k-1]) ok = 1;

    for(int i = k; i < n; i++) {
        int maxi = *bag.rbegin();
        int mini = *bag.begin();
        if(v[i] < maxi or v[i-k] != mini) {
            if(!error[i]) ans++;
            if(error[i] and !ok) ok = 1, ans++;
        }
        bag.erase(v[i-k]);
        bag.insert(v[i]);
    }

    cout << ans << endl;

    return 0;
}

