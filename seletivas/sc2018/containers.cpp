#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
struct node {
    int mat[2][4];
    int d;
};

node est1;
node est2;
map<node, int>dist;

typedef bool (*comp)(node, node
bool compare(node a, node b) {
    return a.d > b.d;
}

node cria(int &matriz[], int dist) {
    node tmp;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 4; j++)
            tmp.mat[i][j] = matriz[i][j];
    tmp.d = dist;
    return tmp;
}

void dij(node est1) { 
    dist.insert(est1, 0);
    priority_queue(node, vector<node>, comp> fila(compare);
    fila.push(est1, 0);
    while(true) {
        int tmp2[2][4];
        memset(tmp2, -1, sizeof tmp);
        node davez = cria(tmp2, -1);
        while(!fila.empty()) { 
            node aux = fila.top();
            fila.pop();
            map<node, int>::iterator it;
            it = dist.find(aux);
            if(it == dist.end()) {
                davez = aux;
                break;
            }
        }
        if(davez.d == -1) break;
        dist.insert(mk(davez, davez.d));

        for(int i = 0; i < 2; i++)   
            for(int j = 0; j < 4; j++) {
                if(i == 1) {
                    aux = davez.mat[i][j]; 
                    davez.mat[i][j] = davez.mat[i+1][j];
                    davez.mat[i+1][j] = aux;



        


int main()
{
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < 4; j++)
            cin >> est1.mat[i][j];
    est1.d = 0;
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < 4; j++)
            cin >> est2.mat[i][j];
    est2.d= INF;
    dij(est1); 
     
    return 0;
}

