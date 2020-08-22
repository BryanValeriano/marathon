#include <bits/stdc++.h>
using namespace std;

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
const int T = 1e6+5;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ini = INF, fim = 0;
    bool ok = 0;

    for(int i = 1; i <= n; i++) cin >> v[i];

    for(int i = n; i >= 1; i--) {
        if(((!ok) and v[i] < v[i-1]) or (ok and v[i] <= v[i-1])) {
            fim = max(fim,i);
            ini = min(ini,i-1);
            ok = 1;
        } else ok = 0;
    }

    if(ini == INF) cout << "1 1\n";
    else {
        while(v[fim+1] == v[fim]) fim++;
        int l = ini, r = fim;
        ok = 1;
        while(l < r) swap(v[l++],v[r--]);
        for(int i = 1; i <= n; i++) ok &= (v[i] >= v[i-1]);
        if(ok) cout << ini << " " << fim << endl;
        else cout << "impossible\n";
    }
    return 0;
}
