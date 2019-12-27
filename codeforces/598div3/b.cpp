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
const int T = 102;

int n;
int v[T];

int getMin(int x) {
    int mini = INF;
    int pos = 0;
    for(int i = x; i < n; i++) {
        if(mini > v[i]) {
            mini = v[i];
            pos = i;
        }
    }
    return pos;
}

void slide(int ini, int fim) {
    if(fim > ini) {
        swap(v[fim],v[fim-1]);
        slide(ini,fim-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
        int ini = 0;
        while(ini < n-1) {
            int z = getMin(ini);
            slide(ini,z);
            ini = max(z,ini+1);
        }
        for(int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}

