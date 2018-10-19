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
set<int> grups[T];

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

pair<int,int> query(int node, int i, int j, int a, int b) {
    if(i > b or j < a) return mp(0,0);
    if(i >= a and j <= b) return mp(1,seg[node]); 
    else { 
        int meio = (i + j) >> 1; 
        pair<int,int> x = query(2*node, i, meio, a, b); 
        pair<int,int> y = query(2*node+1, meio+1, j, a, b);
        if(x.fi and y.fi) return mp(1,x.se and y.se);
        else if(x.fi) return mp(1,x.se);
        else if(y.fi) return mp(1,y.se);
        return mp(0,0); 
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
        grups[pai[x]].insert(x);
        update(1, 1, amigos, x, x, pai[x]);
        return pai[x];
    }
}

void check(int x, int y, int xx, int yy, int fio) {
    int jogoy = mapjogo[y].se;
    int jogox = mapjogo[x].se;
    if(query(1, 1, amigos, qtdjogo[jogoy].fi, qtdjogo[jogoy].se).se)
       if(!resp[jogoy]) resp[jogoy] = fio; 
    if(query(1, 1, amigos, qtdjogo[jogox].fi, qtdjogo[jogox].se).se)
       if(!resp[jogox]) resp[jogox] = fio; 
}

void fusion(int filho, int dad) {
    for(auto id : grups[filho]) {
        grups[dad].insert(id);
        pai[id] = dad;
        update(1, 1, amigos, id, id, dad);
    }
}

void join(int x, int y, int xx, int yy, int fio) {
    int tx = x;
    int ty = y;
    x = find(x);
    y = find(y);

    if(pai[x] == y or pai[y] == x) return;

    if(peso[x] >= peso[y]) {
        fusion(y, x);
        pai[y] = x;
        find(ty);
        //update(1, 1, amigos, y, y, x); 
        check(tx,ty,xx,yy,fio);
        peso[x]++;
    }
    else if(peso[y] >= peso[x]) {
        fusion(x, y);
        pai[x] = y;
        find(tx);
        //update(1, 1, amigos, x, x, y);
        check(tx,ty,xx,yy,fio);
        peso[y]++;
    } 
    else {
        fusion(y, x);
        pai[y] = x;
        find(ty);
        //update(1, 1, amigos, y, y, x);
        check(tx,ty,xx,yy,fio);
        peso[x]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> amigos >> jogos >> fios;
    for(int i = 1; i <= amigos; i++) {
        pai[i] = i;
        grups[i].insert(i);
    }
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
        int a = mapjogo[aa].fi;
        int b = mapjogo[bb].fi;
        join(a,b,aa,bb,i);

    }
    for(int i = 1; i <= jogos; i++) cout << resp[i] << endl;
    return 0;
}

