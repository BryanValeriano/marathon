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

const int T = 4;

int mat[T][T];
vector<ii> v;
int tot;

void gera() {
    for(int i = 0; i < T; i++)
        for(int j = 0; j < T; j++)
            v.eb(i,j);
}

void print() {
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < T; j++) 
            cout << mat[i][j];
        cout << endl;
    }
    cout << endl;
}

void check() {
    //print();
    int ans;
    for(int i = 0; i < T; i++) {
        ans = 0;
        for(int j = 0; j < T; j++)
            ans += mat[i][j];
        if(!(ans&1)) return;
    }
    for(int i = 0; i < T; i++) {
        ans = 0;
        for(int j = 0; j < T; j++)
            ans += mat[j][i];
        if(!(ans&1)) return;
    }
    ans = 0;
    for(int i = 0; i < T; i++) ans += mat[i][i];
    if(!(ans&1)) return;
    ans = 0;
    for(int i = 0; i < T; i++) ans += mat[i][T-i-1];
    if(!(ans&1)) return;
    print();
}

void solve(int at, int c) {
    if(c == tot) { check(); return; }
    if(at == v.size()) return;

    mat[v[at].fi][v[at].se] = 1; 
    solve(at+1, c+1);
    mat[v[at].fi][v[at].se] = 0; 
    solve(at+1, c);
}

int main() {
    ios::sync_with_stdio(false);
    tot = (T*T)/2;
    if(T&1) tot++;
    gera();
    solve(0,0);
    return 0;
}

