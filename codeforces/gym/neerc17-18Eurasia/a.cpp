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
int acum[T][200];
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
            int j = 0;
            while(acum[id[x-y]][j]) j++;
            acum[id[x-y]][j] = i+1;;
            j = 0;
            while(acum[id[x+y]][j]) j++;
            acum[id[x+y]][j] = i+1;
        }
    }


    for(int i = 0; i < T; i++) {
        int k;
        for(k = 0; acum[i][k]; k++) {
            if(at.count(acum[i][k])) at.erase(acum[i][k]);
            else coloca.pb(acum[i][k]);
        }

        for(auto ok : at) acum[i][k++] = ok;

        for(int j = 0; j < coloca.size(); j++) at.insert(coloca[j]);
        coloca.clear();
    }

    at.clear();
    bool flag;

    for(int i = 0; i < n; i++) {
        if(q[i].tipo == 1) at.insert(i+1);
        else {
            point tiro = point(q[i].x,q[i].y);
            flag = 0;
            //if(n == 5e3) cout << id[q[i].x] << " | " << id[q[0].x-q[0].y] << " " << id[q[0].x+q[0].y] << endl;
            int k;
            for(k = 0; acum[id[q[i].x]][k]; k++) {
                int j = acum[id[q[i].x]][k];
                if(!at.count(j)) continue;
                point alvo = point(q[j-1].x, q[j-1].y);
                if(insideCircle(alvo, tiro)) {
                    cout << j << endl;
                    at.erase(j);
                    flag = 1;
                    break;
                }
            }
            if(n == 5e3) cout << k << " --- ";
            if(!flag) cout << -1 << endl;
        }
    }


    return 0;
}

