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
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 3;
ll v[T];
int n,x;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    x--;
    int pos = 0;
    ll mini = INF;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] < mini) mini = v[i], pos = i;
    }

    int dist = (x >= pos? x-pos : x + (n-pos));
    if(mini > 0 and x >= pos) dist += n;

    ll ini = (x >= pos? mini: mini+1);
    int passo = 1;
    int ok = (pos+1)%n;

    while(passo <= dist) {
        v[ok] -= ini;
        ok++;
        ok %= n;
        passo++;
    }
    v[pos] = dist;

    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}

