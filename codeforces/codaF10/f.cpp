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
const int T = 1e6 + 2;
int v[T], bit[T];
int dir[T], esq[T];
map<int,int> qtd;
int n;

void update(int pos, int val) {
    for(;pos<T;pos+=pos&(-pos)) bit[pos] += val;
}

ll query(int pos) {
    ll ans = 0;
    for(;pos;pos-=pos&(-pos)) ans += bit[pos];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        qtd[v[i]]++;
        dir[i] = qtd[v[i]];
    }

    qtd.clear();
    for(int i = n-1; i >= 0; i--) {
        qtd[v[i]]++;
        esq[i] = qtd[v[i]];
        update(esq[i],1);
    }


    ll ans = 0;
    for(int i = 0; i < n-1; i++) {
        update(esq[i],-1);
        ans += query(dir[i]-1);
    }

    cout << ans << endl;
    return 0;
}

