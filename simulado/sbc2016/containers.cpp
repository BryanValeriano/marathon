#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct state {
    int v[2][4];

    state() {}

    void read() {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 4; j++)
                cin >> v[i][j];
    }

    bool operator < (const state &b) const {
        for(int i = 0; i < 2; i++) 
            for(int j = 0; j < 4; j++) 
                if(v[i][j] != b.v[i][j])
                    return v[i][j] < b.v[i][j];
        return false;
    }

    bool operator == (const state &b) const {
        if((*this) < b) return false;
        if(b < (*this)) return false;
        return true;
    }

/*  void operator = (const state &b) {
        for(int i = 0; i < 2; i++) 
            for(int j = 0; j < 4; j++) 
                v[i][j] = b.v[i][j];
    }
*/
    void print() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 4; j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
    }
} beg, last; 

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool pode(int i, int j) {
    return (i>=0 and j>=0 and i<2 and j<4);
}

int go() {
    map<state, int> dist;
    priority_queue<pair<int, state>, vector<pair<int, state> >, greater<pair<int,state> > >pq;

    dist[beg] = 0;
    pq.push(mk(0, beg));

    while(pq.size()) {
        state at = pq.top().se;
        int d = pq.top().fi;
        pq.pop();

        if(at == last) 
            return d;

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    int ii = i + dir[k][0];
                    int jj = j + dir[k][1];

                    if(!pode(ii, jj))   continue;

                    state next = at;

                    swap(next.v[i][j], next.v[ii][jj]);

/*                  next.print();
                    cout << endl;
*/
                    int peso = next.v[i][j] + next.v[ii][jj];

                    if(!dist.count(next) or dist[next] > d + peso) {
                        dist[next] = d + peso;
                        pq.emplace(d+peso, next);
                    }
                }
            }
        }
//      exit(0);
    }

    return INF;
}
 
int main(){
    ios_base::sync_with_stdio(false);

    beg.read();
    last.read();

    cout << go() << endl;
    
    return 0;
}

