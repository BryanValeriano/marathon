#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e5+3;
int resp[T];
int pai[T];
int peso[T];
int contaux[T];
pair<int,int> qtdjogo[T];
pair<int,int> mapjogo[T];
int seg[4*T + 4];
int amigos, jogos, fios;

void build(int node, int i, int j) {
    if(i == j) seg[node] = pai[i];
    else {
        int meio = (i + j) >> 1;
        build(2*node, i, meio);
        build(2*node + 1, meio + 1, j);
        if(seg[2*node] == 0 or seg[2*node+1] == 0) seg[node] = 0;
        else seg[node] = (seg[2*node] == seg[2*node+1]);
    }
}

int query(int node, int i, int j, int a, int b) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    else {
        int meio = (i + j) >> 1;
        query(2*node, i, meio, a, b);
        query(2*node+1, meio+1, j, a, b);
        if(seg[2*node] == 0 or seg[2*node+1] == 0) return 0;
        else return (seg[2*node] == seg[2*node+1]);
    }
}

void update(int node, int i, int j, int a, int b, int val) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) seg[node] = val;
    else {
        int meio = (i + j) >> 1;
        update(2*node, i, meio, a, b, val);
        update(2*node+1, meio+1, j, a, b, val);
        if(seg[2*node] == 0 or seg[2*node+1] == 0) seg[node] = 0;
        else seg[node] = (seg[2*node] == seg[2*node+1]);
    }
}

int find(int x) {
    if(pai[x] == x) return x;
    else {
        pai[x] = find(pai[x]);
        update(1, 1, amigos, x, x, pai[x]);
        return pai[x];
    }
}

void check(int x, int y, int xx, int yy, int fio) {
    int jogoy = mapjogo[y].se;
    int jogox = mapjogo[x].se;
    if(query(1, 1, amigos, qtdjogo[jogoy].fi, qtdjogo[jogoy].se))
       resp[yy] = fio; 
    if(query(1, 1, amigos, qtdjogo[jogox].fi, qtdjogo[jogox].se))
       resp[xx] = fio; 
}

void join(int x, int y, int xx, int yy, int fio) {
    int tx = x;
    int ty = x;
    x = find(x);
    y = find(y);

    if(pai[x] == y or pai[y] == x) return;

    if(peso[x] >= peso[y]) {
        pai[y] = x;
        find(ty);
        //update(1, 1, amigos, y, y, x); 
        check(x,y,xx,yy,fio);
    }
    else if(peso[y] >= peso[x]) {
        pai[x] = y;
        find(tx);
        //update(1, 1, amigos, x, x, y);
        check(x,y,xx,yy,fio);
    } 
    else {
        pai[y] = x;
        peso[x]++;
        find(ty);
        //update(1, 1, amigos, y, y, x);
        check(x,y,xx,yy,fio);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> amigos >> jogos >> fios;
    for(int i = 1; i <= amigos; i++)
        pai[i] = i;
    build(1, 1, amigos);
    int aux;
    for(int i = 1; i <= amigos; i++) {
        cin >> aux;
        mapjogo[i].se = aux;
        qtdjogo[aux].se++;
    }
    qtdjogo[1].fi = 1;
    for(int i = 2; i <= jogos; i++) {
        qtdjogo[i].fi = qtdjogo[i-1].se + 1;
        qtdjogo[i].se += qtdjogo[i].se - 1;
        if(qtdjogo[i].fi == qtdjogo[i].se) resp[i] = 0;
    }
    for(int i = 1; i <= amigos; i++) {
        int jogo = mapjogo[i].se;
        mapjogo[i].fi = qtdjogo[jogo].fi + contaux[jogo];
        contaux[jogo]++;
    }
    for(int i = 1; i <= fios; i++) {
        int aa, bb;
        cin >> aa >> bb;
        int a = mapjogo[a].fi;
        int b = mapjogo[b].fi;
        join(a,b,aa,bb,i);

    }
    for(int i = 1; i <= jogos; i++) cout << resp[i] << endl;
    return 0;
}

