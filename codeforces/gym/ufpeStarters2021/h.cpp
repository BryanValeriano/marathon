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
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);

struct node {
    int v[3][3];
    ii zeroPos;

    bool operator < (const node &b) const {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(v[i][j] != b.v[i][j])
                    return v[i][j] < b.v[i][j];
        return false;
    }

    bool operator == (const node &b) const {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(v[i][j] != b.v[i][j])
                    return false;
        return true;
    }

    //void print() {
    //    for(int i = 0; i < 3; i++) {
    //        for(int j = 0; j < 3; j++) {
    //            cout << v[i][j] << " ";
    //        }
    //        cout << endl;
    //    }
    //    cout << " --------- \n";
    //}
};

struct state {
    node a;
    ll dist;

    state(node a, ll dist) :
        a(a), dist(dist) {}

    bool operator > (const state &b) const {
        if(dist != b.dist) return dist > b.dist;
        return false;
    }
};

node ini;
node fim;

int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
ll cost[10];

bool pode(int i, int j) {
    return (i>=0 and j>=0 and i<3 and j<3);
}

ll dij() {
    map<node,ll> dist;
    set<node> vis;
    priority_queue<state,vector<state>, greater<state>> pq;
    dist[ini] = 0;
    pq.push(state(ini,0));

    while(!pq.empty()) {
        state u = pq.top();
        pq.pop();

        //u.a.print();
        //cout << u.a.zeroPos.fi << " " << u.a.zeroPos.se << " ";
        //cout << u.dist << endl;
        //cout << " xxxx \n";

        if(u.a == fim) return u.dist;
        if(vis.count(u.a)) continue;
        vis.insert(u.a);

        int i = u.a.zeroPos.fi;
        int j = u.a.zeroPos.se;

        for(int k = 0; k < 4; k++) {
            int ii = i + mov[k][0];
            int jj = j + mov[k][1];
            if(!pode(ii,jj)) continue;

            node tmp = u.a;
            tmp.zeroPos = mk(ii,jj);
            ll nDist = u.dist + cost[tmp.v[ii][jj]];
            swap(tmp.v[i][j], tmp.v[ii][jj]);

            state next = state(tmp, nDist);

            if(!dist.count(tmp) || dist[tmp] > nDist) {
                dist[tmp] = nDist;
                pq.push(next);
            }
        }
    }

    return INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    int aux = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> ini.v[i][j];
            if(ini.v[i][j] == 0) ini.zeroPos = mk(i,j);
            fim.v[i][j] = (++aux)%9;
        }
    }
    for(int i = 1; i < 9; i++) cin >> cost[i];
    fim.zeroPos = mk(2,2);
    cout << dij() << endl;
    return 0;
}

