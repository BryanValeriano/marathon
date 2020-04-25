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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5;
const int N = 6;
int druid[T][N];
int n,m,k;

void build(int x) {
   x = min(n,x);
   if(x == 0) {
       for(int j = 0; j < m; j++) cout << 0 << " ";
       cout << endl;
       return;
   }

   multiset<int> bag[m];

    for(int i = 0; i < x; i++)
        for(int j = 0; j < m; j++)
            bag[j].insert(druid[i][j]);

    ll c = 0;
    for(int j = 0; j < m; j++) c += (ll)*bag[j].rbegin();

    if(c <= k) {
        for(int j = 0; j < m; j++) cout << (ll)*bag[j].rbegin() << " ";
        cout << endl;
        return;
    }


    for(int i = x; i < n; i++) {
        c = 0;
        for(int j = 0; j < m; j++) {
            bag[j].insert(druid[i][j]);
            bag[j].erase(bag[j].find(druid[i-x][j]));
            c += (ll)*bag[j].rbegin();
        }
        if(c <= k) {
            for(int j = 0; j < m; j++) cout << (ll)*bag[j].rbegin() << " ";
            cout << endl;
            return;
        }
    }

    return;
}

void add(int i, vector<multiset<int>> &bag) {
    for(int j = 0; j < m; j++) bag[j].insert(druid[i][j]);
}

void erase(int i, vector<multiset<int>> &bag) {
    for(int j = 0; j < m; j++) bag[j].erase(bag[j].find(druid[i][j]));
}

bool can(int i, vector<multiset<int>> &bag) {
    ll c = 0;
    for(int j = 0; j < m; j++) c += (ll)max(druid[i][j],*bag[j].rbegin());
    return c <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> druid[i][j];


    int l = 0;
    int r = 0;
    int ans = 0;
    vector<multiset<int>> bag(6);
    for(int i = 0; i < 6; i++) bag[i].clear();
    add(0,bag);

    while(l < n) {
        while(r+1 < n and can(r+1,bag)) add(r+1,bag),r++;
        if(can(r,bag)) ans = max(ans,r-l+1);
        erase(l,bag); l++;
        if(l < n and l > r) add(l,bag);
        r = max(l,r);
    }

    build(ans);

    return 0;
}

