#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3 + 4;

vector<pair<int,int> >resp;

struct node {
    int prox;
    int ini;
    int fim;
};

node constroi(int a, int b, int c) {
    node tmp;
    tmp.prox = a;
    tmp.ini = b;
    tmp.fim = c;
    return tmp;
}
vector<node> graph[T];
bool visit[T];
int goal;

void dfs(int atual, pair<int,int>ind) {
    if(atual == goal) {
        resp.pb(ind);
        return;
    }
    if(visit[atual]) return;    
    visit[atual] = true;    

    for(int i = 0; i < graph[atual].size(); i++) {
        if(graph[atual][i].ini <= ind.sec) {    
            int minatual = max(ind.fi, graph[atual][i].ini);
            int maxatual = min(ind.sec, graph[atual][i].fim);
            pair<int,int>tmp = mk(minatual, maxatual);
            dfs(graph[atual][i].prox, tmp);
        }
    }
    visit[atual] = false;
}

bool cmp(pair<int,int>&a, pair<int,int>&b) {
    return a.fi < b.fi;
}

int conta() {
    int cont = 0;
    sort(resp.begin(), resp.end(), cmp); 
    int l = resp[0].fi;
    int r = resp[0].sec;
    for(int i = 1; i < resp.size(); i++) {
        if(resp[i].fi > r) {
            cont += (r - l) + 1;
            l = resp[i].fi;
            r = resp[i].sec;
        }
        else if(resp[i].sec <= r) {
            continue;
        }
        else if(resp[i].fi <= r) {
            r = resp[i].sec;
        } 
    }
    cont += (r - l) + 1;
    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int comeco;
    cin >> comeco >> goal;
    int a, b, c, d;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;    
        node tmp = constroi(b, c, d);   
        graph[a].pb(tmp);
    }
    pair<int,int>ind;
    ind = mk(1, k);
    dfs(comeco, ind);
    cout << conta() << endl;   
    
    return 0;
}


