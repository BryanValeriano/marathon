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
const int T = 1e5 + 3;
int n, k, r, c;
int br[T], bc[T];

int L(int x, int y) { return(y-1); }
int D(int x, int y) { return(x-1); }
int R(int x, int y) { return(n-y); }
int U(int x, int y) { return(n-x); }
int DUL(int x, int y) { return min(U(x,y), L(x,y)); }
int DUR(int x, int y) { return min(U(x,y), R(x,y)); }
int DDL(int x, int y) { return min(D(x,y), L(x,y)); }
int DDR(int x, int y) { return min(D(x,y), R(x,y)); }

bool dig(int x, int y) { return (abs(x - r) == abs(y - c)); }

int main() {
    ios::sync_with_stdio(false);
    set<int>lins;
    cin >> n >> k >> r >> c;
    
    ll score = 0;
    score += L(r,c) + R(r,c) + U(r,c) + D(r,c) + DUL(r,c) + DUR(r,c) + DDL(r,c) + DDR(r,c);
    int le = 0, ri = 0, u = 0, d = 0, dul = 0, dur = 0, ddl = 0, ddr = 0;
    for(int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        if(dig(row,col)) {
            if(col < c and row > r) 
                dul = max(dul,DUL(row,col)+1);
            else if(col > c and row > r) 
                dur = max(dur,DUR(row,col)+1);
            else if(col < c and row < r) 
                ddl = max(ddl,DDL(row,col)+1);
            else if(col > c and row < r) 
                ddr = max(ddr,DDR(row,col)+1);
        }
        else if(row == r) {
            if(col < c) le = max(le,L(row,col)+1);
            else ri = max(ri,R(row,col)+1);
        }
        else if(col == c) {
            if(row > r) u = max(u,U(row,col)+1);
            else d = max(d, D(row,col)+1);
        }
    }
    score -= (le + ri + u + d + dul + dur + ddl + ddr); 
    cout << score << endl;
    return 0;
}

