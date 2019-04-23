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

const int T = 2e5 + 10;

unordered_set<int> vis;
unordered_map<int,int> qtd;
unordered_map<int,stack<int> > pos;
vii bag;
int v[T];


int main() {
    ios::sync_with_stdio(false);
    int n, m;
    int impar = 0, par = 0;
    int iterP = 2, iterI = 1;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        vis.insert(v[i]);
        qtd[v[i]]++;
        if(v[i] & 1) impar++;
        else par++;
        pos[v[i]].push(i);
    }

    for(auto z : qtd) bag.eb(z.se,z.fi);
    sort(bag.begin(), bag.end());

    int i = 0;
    ll troca = 0;

    while(i < bag.size()) {

        while(bag[i].se & 1 and par < impar and bag[i].fi > 1) { 
            while(vis.count(iterP)) iterP += 2;
            if(iterP > m) { cout << -1 << endl; return 0; }
            v[pos[bag[i].se].top()] = iterP;
            pos[bag[i].se].pop();
            bag[i].fi--;
            vis.insert(iterP);
            troca++;
            par++;
            impar--;
        }

        while(bag[i].se & 1 and par >= impar and bag[i].fi > 1) {
            while(vis.count(iterI)) iterI += 2;
            if(iterI > m) { cout << -1 << endl; return 0; }
            v[pos[bag[i].se].top()] = iterI;
            pos[bag[i].se].pop();
            bag[i].fi--;
            vis.insert(iterI);
            troca++;
        }

        while(!(bag[i].se & 1) and par > impar and bag[i].fi > 1) {
            while(vis.count(iterI)) iterI += 2;
            if(iterI > m) { cout << -1 << endl; return 0; }
            v[pos[bag[i].se].top()] = iterI;
            pos[bag[i].se].pop();
            bag[i].fi--;
            vis.insert(iterI);
            troca++;
            par--;
            impar++;
        }


        while(!(bag[i].se & 1) and par <= impar and bag[i].fi > 1) {
            while(vis.count(iterP)) iterP += 2;
            if(iterP > m) { cout << -1 << endl; return 0; }
            v[pos[bag[i].se].top()] = iterP;
            pos[bag[i].se].pop();
            bag[i].fi--;
            vis.insert(iterP);
            troca++;
        }

        i++;
    }

    i = 0; 

    while(i < bag.size()) {

        if(!(bag[i].se&1) and impar < par) {
            while(vis.count(iterI)) iterI += 2;
            if(iterI > m) { cout << -1 << endl; return 0; }
            v[pos[bag[i].se].top()] = iterI;
            pos[bag[i].se].pop();
            bag[i].fi--;
            vis.insert(iterI);
            vis.erase(bag[i].se);
            troca++;
            par--;
            impar++;
        }

        if(bag[i].se&1 and par < impar) {
            while(vis.count(iterP)) iterP += 2;
            if(iterP > m) { cout << -1 << endl; return 0; }
            v[pos[bag[i].se].top()] = iterP;
            pos[bag[i].se].pop();
            bag[i].fi--;
            vis.insert(iterP);
            vis.erase(bag[i].se);
            troca++;
            par++;
            impar--;
        }

        i++;
    }


    if(par == impar) {
        cout << troca << endl;
        for(int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    } else cout << -1 << endl;

    return 0;
}

