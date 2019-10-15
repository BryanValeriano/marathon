#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef tuple<int,int,int,int> ti;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e7 + 5e6;

bitset<T> crivo;
vector<int> primes;
vector<int> g[T];

void init() {
    crivo[0] = crivo[1] = 1;

    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

ll junt(int x, int y) {
    int ans = 0;
    ll casa = 1;

    while(y) {
        ans += (y%10)*casa;
        casa *= 10;
        y /= 10;
    }
    while(x) {
        ans += (x%10)*casa;
        casa *= 10;
        x /= 10;
    }

    return ans;
}

void build(int x) {
    int gol = x;
    int y = x%10;

    x /= 10;
    int casa = 10;

    while(x) {
        if(!crivo[x] and !crivo[y] and junt(x,y) == gol and !crivo[junt(y,x)])
            g[x].pb(y), g[y].pb(x);

        y += (x%10)*casa;
        casa *= 10;
        x /= 10;
    }

}

vector<int> wat;
vector<vector<int>> wtf;
set<ti> bag;

void save() {
    vector<int> p = wat;
    sort(p.begin(),p.end());
    ti x = make_tuple(p[0],p[1],p[2],p[3]);
    bag.insert(x);
}

bool naive(int u) {
    wat.pb(u);
    if(wat.size() == 4) { save(); wat.pop_back(); return 1; }

    bool ans = 0;

    for(int v : g[u]) {
        int x = 0;
        for(int k : wat) {
            if(!binary_search(g[v].begin(),g[v].end(), k)) break;
            x++;
        }
        if(x == wat.size()) ans |= naive(v);
    }

    wat.pop_back();
    return ans;
}

bool dist(int i, int j) {
    set<int> p;
    for(int k = 0; k < 4; k++) p.insert(wtf[i][k]), p.insert(wtf[j][k]);
    return p.size() == 5;
}

bool isPrime(ll x) {
    for(int i = 0; i < primes.size() and (ll)primes[i]*(ll)primes[i] <= x; i++) {
        if(x % primes[i] == 0) return 0;
    }
    return 1;
}

bool tent(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int ok = 0;
        for(int j = 0; j < 4; j++) {
            if(i == j) break;
            if(isPrime(junt(wtf[x][i],wtf[y][j]) and isPrime(junt(wtf[y][i],wtf[x][j])))) ok++;
        }
        if(ok == 4) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();

    for(int i = 0; i < primes.size(); i++) build(primes[i]);

    for(int i = 0; i < primes.size(); i++) {
        int j = primes[i];
        sort(g[j].begin(), g[j].end());
        g[j].resize(unique(g[j].begin(), g[j].end()) - g[j].begin());
    }

    for(int i = 0; i < primes.size(); i++) naive(primes[i]);
    cout << bag.size() << endl;

    for(auto x : bag) {
        vector<int> z;
        int a,b,c,d;
        tie(a,b,c,d);
        z.pb(a);
        z.pb(b);
        z.pb(c);
        z.pb(d);
        wtf.pb(z);
    }

    for(int i = 0; i < wtf.size(); i++)
        for(int j = i+1; j < wtf.size(); j++)
            if(dist(i,j) == 1)
                if(tent(i,j)) cout << "OH YEAH" << endl;


    //for(int i = 0; i < g[673].size(); i++) cout << g[673][i] << endl;
    //cout << crivo[673109] << endl;
    //cout << crivo[109673] << endl;
    return 0;
}

