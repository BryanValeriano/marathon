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
const int T = 192500;
int v[T];

bool between(int x, int d, int i, int f) {
    x %= d;
    if(i <= f) return !(x > i and x < f);
    return !(x > i or x < f);
}

void update(int d, int i, int f) {
    for(int k = 0; k < T; k++)
        v[k] += between(k,d,i,f);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int maxi = 0;

    for(int i = 0; i < n; i++) {
        int d,ii,f; cin >> d >> ii >> f;
        update(d,ii,f);
        maxi = max(maxi,1825*d);
    }

    for(int i = 0; i <= maxi; i++) {
        if(v[i] == n) {
            cout << i << endl;
            return 0;
        }
    }

    cout << "impossible" << endl;

    return 0;
}

