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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 3e5 + 3;

vii hp;
vii v;
set<ii> hpp;
set<ii> atk;
int ans[T][2];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int h,t;

    for(int i = 0; i < n; i++) {
        cin >> t >> h;
        v.eb(h,t);
        hp.eb(h,i);
        atk.emplace(t,i);
    }

    sort(hp.begin(), hp.end());

    for(int i = 0; i < n; i++) {
        auto it = atk.rbegin();
        if(it->se == i) it++;
        if(it->fi >= v[i].fi) ans[i][0] = v[i].se, ans[i][1] = it->se;
    }

    int x = 0;

    for(auto at : atk) {
        while(x < n and at.fi >= hp[x].fi) hpp.emplace(mk(v[hp[x].se].se,hp[x].se)), x++;

        bool flag = 0;
        if(hpp.count(at)) flag = 1, hpp.erase(at);

        if(hpp.size()) {
            auto ok = hpp.rbegin();
            if(ok->fi >= v[at.se].fi) ans[at.se][0] = at.fi + ok->fi, ans[at.se][1] = ok->se;
            else ans[at.se][0] = ok->fi, ans[at.se][1] = ok->se;
        }

        if(flag) hpp.insert(at);
    }

    int best = 0;
    int id = 0;
    int id2 = 1;

    for(int i = 0; i < n; i++) {
        if(ans[i][0] > best) {
            best = ans[i][0];
            id = i, id2 = ans[i][1];
        }
    }

    cout << best << endl;
    cout << id+1 << " " << id2+1 << endl;

    return 0;
}

