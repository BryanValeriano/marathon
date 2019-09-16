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

const int T = 4e5 + 10;

struct point {
    ll x,y;
    point(ll x, ll y) :
        x(x), y(y) {}
};

struct query {
    int tipo;
    ll x,y;
};

int n;
vector<query> q;
vector<int> coloca;
vector<int> acum[T];
map<int,int> id;
set<int> at;

bool insideCircle(point c, point p) {
    ll r = c.y;
    ll dx = p.x - c.x, dy = p.y - c.y;
    ll euc = dx*dx + dy*dy, rsq = r*r;
    return euc < rsq;
}

int main() {
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c, q.pb({a,b,c});
        if(a == 2) id[b] = 0;
        else id[b-c] = 0, id[b+c] = 0;
    }

    int i = 0;
    for(map<int,int>::iterator it = id.begin(); it != id.end(); ++it)
        it->se = i++;

    for(int i = 0; i < q.size(); i++) {
        if(q[i].tipo == 1) {
            int x = q[i].x;
            int y = q[i].y;
            acum[id[x-y]].pb(i);
            acum[id[x+y]].pb(i);
        }
    }


    for(int i = 0; i < T; i++) {
        for(int j = 0; j < acum[i].size(); j++) {
            if(at.count(acum[i][j])) at.erase(acum[i][j]);
            else coloca.pb(acum[i][j]);
        }

        for(auto ok : at) acum[i].pb(ok);

        for(int j = 0; j < coloca.size(); j++) at.insert(coloca[j]);
        coloca.clear();
    }

    at.clear();
    int alv = 0;
    bool flag;

    for(int i = 0; i < n; i++) {
        if(q[i].tipo == 1) at.insert(i);
        else {
            point tiro = point(q[i].x,q[i].y);
            flag = 0;
            for(int j : acum[id[q[i].x]]) {
                if(!at.count(j)) continue;
                point alvo = point(q[j].x, q[j].y);
                if(insideCircle(alvo, tiro)) {
                    cout << j+1 << endl;
                    at.erase(j);
                    flag = 1;
                    break;
                }
            }
            if(n == 5e3) cout << acum[id[q[i].x]].size() << " -- ";
            if(!flag) cout << -1 << endl;
        }
    }


    return 0;
}

