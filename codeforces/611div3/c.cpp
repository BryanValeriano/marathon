#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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

const int T = 2e5 +5;
int v[T];
set<int> fr;
set<ii> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 1; i <= n; i++) fr.insert(i);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i]) fr.erase(v[i]);
    }

    for(auto x : fr) {
        if(!v[x]) bag.emplace(0,x);
        else bag.emplace(1,x);

    }


    for(int i = n; i >= 1; i--) {
        if(!v[i]) {
            ii at = *bag.begin();
            int x = at.se;
            if(x != i) {
                v[i] = x;
                bag.erase(at);
            } else {
                auto iter = bag.begin();
                iter++;
                at = *iter;
                x = at.se;
                v[i] = x;
                bag.erase(at);
            }
            if(bag.count(ii(0,i))) {
                bag.erase(ii(0,i));
                bag.emplace(1,i);
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}

