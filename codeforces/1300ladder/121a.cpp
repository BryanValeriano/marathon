#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll MAX = 10000000000LL;
vector<ll>row;

void build(ll atual) {
    if(atual > MAX) return;
    if(atual > 0) 
        row.pb(atual);
    build(atual * 10LL + 4LL);
    build(atual * 10LL + 7LL);
}

int main() {
    ios::sync_with_stdio(false);
    int l, r; cin >> l >> r;
    build(0);
    sort(row.begin(), row.end());
    
    ll atual = 0;
    ll resp = 0;
    ll fim = 0;
    int i = 0;
    while(row[i] < l) i++;
    while(atual < r) {
        atual = row[i];
        fim = atual;
        if(atual > r) fim = r;
        resp += (fim - l + 1) * atual;
        l = atual+1;
        i++;
    }
    cout << resp << endl;

    return 0;
}

