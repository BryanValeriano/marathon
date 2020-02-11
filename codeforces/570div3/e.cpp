#include <bits/stdc++.h>
using namespace std;

#define pb      push_back
#define eb      emplace_back
#define mk      make_pair
#define fi      first
#define se      second
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl
#define endl    '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n,k;
string s;
unordered_set<string> vis;

int solve() {
    queue<string> fila;
    fila.push(s);

    int qtd = 0;
    int ans = 0;

    while(!fila.empty() and qtd < k) {
        qtd++;
        string at = fila.front();
        fila.pop();

        ans += at.size();

        string tmp, tmp2;

        for(int i = 0; i < at.size(); i++) {
            tmp2 = tmp;
            tmp += at[i];
            for(int j = i+1; j < at.size(); j++) tmp2 += at[j];
            if(!vis.count(tmp2)) fila.emplace(tmp2), vis.insert(tmp2);
        }

    }

    if(qtd == k) return n*k - ans;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    cout << solve() << endl;
    return 0;
}


