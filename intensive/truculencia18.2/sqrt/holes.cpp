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
const int T = 1e5 + 10;
const int SZ = sqrt(T);
int v[3][T];
int n, q;

void build() {
    for(int i = n; i >= 1; i--) {
        if(i + v[0][i] > n) {
            v[1][i] = 1;
            v[2][i] = i;
        } else if( (i + v[0][i])/SZ == i/SZ){
            v[1][i] = v[1][i + v[0][i]] + (i + v[0][i] == v[2][i + v[0][i]]? 0 : 1);
            v[2][i] = v[2][i + v[0][i]];
        } else {
            v[1][i] = 1;
            v[2][i] = i + v[0][i];
        }
    }
}

void update(int pos, int val) {
    int bucket = pos/SZ;
    v[0][pos] = val;
    if(pos + v[0][pos] > n) {
        v[1][pos] = 1;
        v[2][pos] = pos;
    }
    else if((pos + v[0][pos])/SZ == bucket) {
        v[1][pos] = v[1][pos + v[0][pos]] + (pos + v[0][pos] == v[2][pos + v[0][pos]]? 0 : 1);

        v[2][pos] = v[2][pos + v[0][pos]];
    } else {
        v[1][pos] = 1;
        v[2][pos] = pos + v[0][pos];
    }
    for(int i = pos-1; i >= 1 and bucket == i/SZ; i--) {
        if(i + v[0][i] > n) {
            v[1][i] = 1;
            v[2][i] = i;
        } else if( (i + v[0][i])/SZ == bucket){
            v[1][i] = v[1][i + v[0][i]] + (i + v[0][i] == v[2][i + v[0][i]]? 0 : 1);
            v[2][i] = v[2][i + v[0][i]];
        } else {
            v[1][i] = 1;
            v[2][i] = i + v[0][i];
        }
    }
}

ii query(int pos) {
    int ans = 0;
    int ini = pos;
    while(true) {
        ans += v[1][pos];
        if(pos == v[2][pos]) break;
        pos = v[2][pos];
    }
    return mk(pos,ans);
}

//void print() {
//    for(int i = 1; i <= n; i++) 
//        cout << i << " " << v[0][i] << " " << v[1][i] << " " << v[2][i] << endl;
//    cout << endl;
//}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &v[0][i]);
    build();
    int op, a, b;
    for(int i = 0; i < q; i++) {
        scanf("%d ", &op);
        if(op == 0) {
            scanf("%d %d", &a, &b);
            update(a,b);
        } else {
            scanf("%d", &a);
            ii ans = query(a);
            printf("%d %d\n", ans.fi, ans.se);
        }
//        print();
    }
    return 0;
}

