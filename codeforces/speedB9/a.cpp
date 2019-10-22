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

const int T = 1e3 + 5;
vector<int> g[T];
int used[T];
int pai[T];
int peso[T];
int ans[T];
int qtd[30];
string s;

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

void exec(int t) {
    for(int i = 2; i <= t; i++) {
        if(g[i].size() == 0) {
            g[i].pb(i);
            for(int j = i+i; j <= t; j += i) g[j].pb(i);
        }
    }

    for(int i = 2; i <= t; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            int a = i;
            int b = g[i][j];
            join(a,b);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    init();
    exec(s.size());
    for(int i = 0; i < s.size(); i++) qtd[s[i]-'a']++;

    priority_queue<ii, vector<ii> > gr;  
    priority_queue<ii, vector<ii> > pq;  

    for(int i = 2; i <= s.size(); i++) 
        if(!used[find(i)]) {
            used[find(i)] = 1;
            gr.emplace(peso[find(i)], find(i));
        }

    for(int i = 0; i < 30; i++) 
        if(qtd[i])
            pq.emplace(qtd[i],i);

    while(!gr.empty()) {
        ii at = gr.top();
        gr.pop();
        ii xt = pq.top();
        pq.pop();

        if(at.fi > xt.fi) {
            cout << "NO" << endl;
            exit(0);
        }

        for(int i = 2; i <= s.size(); i++) 
            if(find(i) == at.se) ans[i] = xt.se; 

        xt.fi -= at.fi;
        if(xt.fi) pq.emplace(xt);
    }

    cout << "YES" << endl;
    ans[1] = pq.top().se;
    for(int i = 1; i <= s.size(); i++) cout << (char)(ans[i]+'a');
    cout << endl;
    
    return 0;
}

