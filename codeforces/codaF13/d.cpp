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
const int T = 5e3+4;
int v[T], pre[T][T];
int n;

int state(int x, int i) {
    int maiores = pre[x][i-1];
    int menores = n-i-(pre[x][n]-pre[x][i]);
    //cout << x << " " << i << " " << maiores << " " << menores << endl;
    return maiores+menores;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];

    int r = 0;

    for(int i = 0; i < n; i++) {
        int big = 0;
        for(int j = 1; j <= n; j++) {
            big = (v[j] > i);
            pre[i][j] = pre[i][j-1] + big;
            if(v[j] == i) r += pre[i][j];
        }
    }

    int ans = r;
    int qtd = 1;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++) {
            int tmp = r;
            tmp -= state(v[i],i) + state(v[j],j);
            tmp += state(v[i],j) + state(v[j],i);
            tmp += (v[j] > v[i]);
            if(tmp==ans) qtd++;
            if(tmp < ans) ans = tmp, qtd=1;
        }

    cout << ans << " " << qtd << endl;

    return 0;
}

