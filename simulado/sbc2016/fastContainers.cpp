#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef pair<int,int> ii;
typedef vector< pair<int,int> >vii[1010];
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 2e7;
vii ind;
int dist[T];
bool processado[T];
map<int,int>id;
int pot[10];
int ele[2][4];

struct state {
    int v[2][4];

    state() {}

    void read() {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 4; j++) {
                scanf("%d ", &v[i][j]);
            }
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

    int dist() {
        int sum = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 4; j++) {
                if(ind[v[i][j]].size() == 1) {
                    ii tmp = ind[v[i][j]][0];
                    int manhatam = (abs(i - tmp.fi) + abs(j - tmp.se)); 
                    sum += v[i][j] * manhatam;
                }
            }
        }
        return sum;
    }
} beg, last; 

struct node {
    state a;
    int d;
    ll aStar;

    node (state a, int d, int aStar) :
        a(a), d(d), aStar(aStar) {}

    bool operator < (const node &b) const {
        return d + aStar < b.d + b.aStar;
        return false;
    }
    bool operator > (const node &b) const {
        return d + aStar > b.d + b.aStar;
        return false;
    }
};

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int convert(const state &k) {
    int tmp = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            tmp *= 8;
            tmp += id[k.v[i][j]];
        }
    }
    return tmp;
}

bool pode(int i, int j) {
    return (i>=0 and j>=0 and i<2 and j<4);
}

int go() {
    priority_queue<node, vector<node>, greater<node> >pq;

    int indice;
    dist[indice] = 0;
    pq.push(node(beg, 0LL, beg.dist()));

    state at = pq.top().a;
    while(true) {
        indice = -1;
        int d;
        int aStar;
        
        while(!pq.empty()) {
            at = pq.top().a;
            d = pq.top().d;
            pq.pop();
            indice = convert(at);
            if(!processado[indice]) {
                break;
            }
        }

        if(indice == -1) break;    

        processado[indice] = true;
        if(at == last) 
            return d;


        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    int ii = i + dir[k][0];
                    int jj = j + dir[k][1];

                    if(!pode(ii, jj))   continue;

                    state next = at;

                    int indice_nxt = indice + pot[ele[i][j]] * (id[next.v[ii][jj]]-id[next.v[i][j]])
                        + pot[ele[ii][jj]]*(id[next.v[i][j]]-id[next.v[ii][jj]]);

                    swap(next.v[i][j], next.v[ii][jj]);

                    int realD = next.v[i][j] + next.v[ii][jj];
                    int peso = next.dist();
                    
                    
                    if(dist[indice_nxt] == 0 or dist[indice_nxt] > d + peso + realD) {
                        dist[indice_nxt] = d + peso + realD;
                        pq.push(node(next, d + realD, peso));
                    }
                }
            }
        }
    }

    return INF;
}
 
int main(){
    beg.read();
    last.read();
    vector<int>ve;
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < 4; j++) { 
            ve.pb(last.v[i][j]);
            ind[last.v[i][j]].eb(i,j); 
        }
    for(int i = 0; i < 8; i++) 
        id[ve[i]] = i;

    pot[0] = 1;
    for(int i = 1; i < 8; i++)
        pot[i] = pot[i-1] * 8;

    int at = 7;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 4; j++)
            ele[i][j] = at--;

    printf("%d\n", go());
    
    return 0;
}

