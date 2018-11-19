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
const int T = 3e4 + 10;
const int R = 2e5 + 10;
int bit[T];

void update(int idx, int val) {
    for(int i = idx; i < T; i += i&-i) 
        bit[i] += val;
}

int query(int idx) {
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i) 
        sum += bit[i];
    return sum;
}

struct node {
    int type, ini, fim, val, pos;

    node(int type, int ini, int fim, int val, int pos) :
        type(type), ini(ini), fim(fim), val(val), pos(pos) {}
};

bool cmp(const node &a, const node &b) {
    if(a.val != b.val) return a.val > b.val;
    else return a.type > b.type;
}

int main() {
    int n; scanf("%d", &n);
    int aux, aux2, aux3;
    vector<node>row;
    for(int i = 0; i < n; i++) {
        scanf("%d", &aux);
        row.pb(node(1,0,0,aux,i+1));
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        scanf("%d %d %d", &aux, &aux2, &aux3);
        row.pb(node(2,aux,aux2,aux3,i));
    }
    sort(row.begin(), row.end(), cmp);
    int ans[R];
    for(auto ele : row) {
        if(ele.type == 1) update(ele.pos,1);
        else ans[ele.pos] = query(ele.fim) - query(ele.ini-1);
    }
    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);

    return 0;
}

