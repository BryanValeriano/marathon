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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> in(n+3,0);
    int folhas = 0;

    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        in[a]++, in[b]++;
        if(in[a] == 1) folhas++;
        else if(in[a] == 2) folhas--;
        if(in[b] == 1) folhas++;
        else if(in[b] == 2) folhas--;
    }

    cout << (folhas/2) + (folhas&1) << endl;

    return 0;
}

