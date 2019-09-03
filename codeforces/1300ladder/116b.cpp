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
const int T = 12;
int n, m;
char mat[T][T];    
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
struct node {
    int i;
    int j;
    int grau;

    node(int i, int j, int grau) :
        i(i), j(j), grau(grau) {}

    bool operator > (const node &b) const {
        if(grau !=  b.grau)
            return grau > b.grau;
        return false;
    }
};

bool tem(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m and mat[i][j] == 'P');
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int pigs = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'P') pigs++;
        }
    }
    
    priority_queue<node, vector<node>, greater<node> > pq;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'W') {
                int deg = 0;
                for(int k = 0; k < 4; k++) {
                    int ii = i + mov[k][0];
                    int jj = j + mov[k][j];
                    if(tem(ii,jj)) deg++;
                }
                pq.push(node(i, j, deg));
            }
        }
    }
    int pigs2 = pigs;
    while(pigs and !pq.empty()) {
        node tmp = pq.top();
        pq.pop();
        for(int k = 0; k < 4; k++) {
            int ii = tmp.i + mov[k][0];
            int jj = tmp.j + mov[k][1];
            if(tem(ii, jj)) {
                mat[ii][jj] = '.';
                pigs--;
                break;
            }
        }

    }
    cout << pigs2 - pigs << endl; 
    return 0;
}

