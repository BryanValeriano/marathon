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
pair<int,int> row[T];
int n;
ll tree[T];
ll tree2[T];

bool cmp(const pair<int,int> &a, const pair<int,int>&b) {
    return a.fi < b.fi;
}

void update(int idx, int val) {
    while(idx <= n) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
void update2(int idx, int val) {
    while(idx <= n) {
        tree2[idx] += val;
        idx += (idx & -idx);
    }
}

ll query(int idx) {
    ll sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

ll query2(int idx) {
    ll sum = 0;
    while(idx > 0) {
        sum += tree2[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

pair<int,ll> bin(ll gol) {
    int ini = 1;
    int fim = n;
    int meio = n/2;
    ll tent  = 0;
    while(ini < fim) {
        meio = (ini + fim)/2;
        tent = query(meio);
        if(tent > gol) fim = meio - 1;
        else if(tent < gol) ini = meio + 1;
        else break;
    }
    if(tent > gol) {
        meio--;
        tent = query(meio);
        return mk(meio, tent);
    }
    return mk(meio, tent);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int aux;
    ll din; cin >> din;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> row[i].fi;
        row[i].se = i;
        update(i, row[i].fi);
        update2(i, 1);
        sum += row[i].fi;
    }
    sort(row + 1, row + n+1, cmp);
    int top = n;
    ll resp = 0;
    while(top > 0 && din != 0 && sum != 0) {
        cout << top << " " << din << " " << sum << endl;
        if(din < sum) {
            pair<int,ll> melhor = bin(din); 
            din -= melhor.se;
            resp += query2(melhor.fi);
            int tmp = row[top].fi;
            update(row[top].se, 0);
            update2(row[top].se, 0);
            sum -= tmp;
            top--;
        } else {
            ll vezes = din/sum;
            din -= vezes * sum;
            vezes *= top;
            resp += vezes;
        }     
    }

    cout << resp << endl;

    return 0;
}

