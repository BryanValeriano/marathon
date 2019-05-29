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

const int T = 103;

struct node {
    int vot, l, id;

    bool operator < (const node &b) {
        if(vot != b.vot) return vot > b.vot;
        return l < b.l;
    }
};

typedef vector<node> vn;

int n,k,m,a,rest;
int vots[T];
int last[T];
vn v;

vn melhor(int x) {
    vn vv = v;

    for(int i = 0; i < n; i++)
        if(v[i].id == x) { vv[i].vot += rest, vv[i].l = INF; break; }

    sort(vv.begin(), vv.end());
    while(vv.size() and vv.rbegin()->vot == 0) vv.pop_back();

    return vv;
}

vn pior(int x) {
    vn vv = v;
    int ini, gol;
    int r = rest;
    
    for(int i = 0; i < n; i++)
        if(v[i].id == x) { ini = i+1, gol = v[i].vot+1; break; }

    while(ini < n and r) {
        while(r and vv[ini].vot < gol) vv[ini].vot++, r--, vv[ini].l = m-rest;
        ini++;
    }

    sort(vv.begin(), vv.end());
    while(vv.size() and vv.rbegin()->vot == 0) vv.pop_back();
    
    return vv;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> m >> a;
    rest = m-a;
    int x;

    for(int i = 0; i < a; i++) {
        cin >> x;
        vots[x]++;
        last[x] = i;
    }
    
    for(int i = 1; i <= n; i++) v.pb({vots[i],last[i],i});
    sort(v.begin(), v.end());    

    for(int i = 1; i <= n; i++) { 
        int ori = INF, b = INF, w = INF;
        vn best = melhor(i);
        vn worst = pior(i);

        for(int j = 0; j < n; j++) {
            if(v[j].id == i) ori = j;
            if(j < best.size() and best[j].id == i) b = j;
            if(j < worst.size() and worst[j].id == i) w = j;
        }
        
        if(ori < k and w < k) cout << 1 << " ";
        else if(b < k) cout << 2 << " ";
        else cout << 3 << " ";
    }

    cout << endl;
        

    return 0;
}

