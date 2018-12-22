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
int n;

unordered_map<string, vector<string> > g;
unordered_map<string, string> pai;
unordered_set<string> vis;
stack<string> path;
string ori, dest;

void print() {
    cout << path.size() << endl;
    while(!path.empty()) {
        cout << path.top() << endl;
        path.pop();
    }
}

void buildpath() {
    int i = 2;
    string atual = dest;
    while(atual != ori) {
        if(i % 2 == 0) path.push(atual);
        atual = pai[atual];
        i++;
    }
    path.push(ori);
}

bool bfs() {
    queue<string> list; 
    list.push(ori);
    while(!list.empty()) {
        string atual = list.front();
        list.pop();

        if(atual == dest) return true;

        for(int i = 0; i < g[atual].size(); i++) {
            string filho = g[atual][i];
            if(!vis.count(filho)) {
                vis.insert(filho);
                pai[filho] = atual;
                list.push(filho);
            }
        }
    }
    return false;
}

void expand(string s) {
    for(int i = 0; i < s.size(); i++) {
        string tmp = s;
        tmp[i] = '-';
        g[s].pb(tmp);
        g[tmp].pb(s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    cin >> n;
    string aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        if(i == 0) ori = aux;
        else if(i == n-1) dest = aux;
        expand(aux);
    }
    if(!bfs()) { cout << "FAIL" << endl; return 0; }
    buildpath();    
    print();
    return 0;
}

