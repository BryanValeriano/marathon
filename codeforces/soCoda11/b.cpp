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
const int T = 3e6 + 5;

vii v[T];
set<ii> bag;
int n;
string id[T];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int fim = 0;

    for(int i = 0; i < n; i++) {
        cin >> id[i];
        int m = id[i].size();
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            v[x].eb(i,x);
            v[x+m].eb(i,-x);
            fim = max(fim,x+m);
        }
    }

    string ans;

    for(int i = 1; i < fim; i++) {

        while(v[i].size()) {
            ii at = v[i].back();
            v[i].pop_back();
            if(at.se < 0) {
                at.se = -at.se;
                if(bag.count(at)) bag.erase(at);
            } else {
                auto tmp = bag.lower_bound(mk(at.fi,0));
                if(tmp != bag.end() and tmp->fi == at.fi) bag.erase(tmp);
                bag.insert(at);
            }
        }

        if(!bag.empty()) {
            ii at = *bag.begin();
            ans += id[at.fi][i-at.se];
        } else ans += 'a';
    }

    cout << ans << endl;

    return 0;
}

