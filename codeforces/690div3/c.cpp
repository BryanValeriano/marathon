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
int v[12];

void solve(int qtd, int x) {
    int tmp = 1;
    v[0] = 1;
    if(qtd >= 2) v[1] = 0;

    for(int i = 2; i < qtd; i++) v[i] = i, tmp += i;

    //for(int i = 0; i < qtd; i++) cout << v[i];
    //cout << " | ";

    int last = 9;
    for(int i = qtd-1; i >= 0; i--) {
        while(tmp < x && v[i] < last) tmp++, v[i]++;
        last = v[i]-1;
    }

    for(int i = 0; i < qtd; i++) cout << v[i];
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int x; cin >> x;
        int sum = 0;
        bool ans = 0;
        for(int i = 1; i <= 10; i++) {
            sum += 10-i;
            if(sum >= x) {
                solve(i,x);
                ans = 1;
                break;
            }
        }
        if(!ans) cout << -1 << endl;
    }
    return 0;
}

