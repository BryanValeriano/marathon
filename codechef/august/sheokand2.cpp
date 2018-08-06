#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
vector<ll>row;

ll search(ll N) {
    int ini = 0;
    int fim = row.size();
    while(ini < fim) {
        int meio = (ini + fim)/2;
        if(row[meio] < N) fim = meio - 1;
        else if(row[meio] > N) ini = meio + 1;
        else { ini = meio; break; }
    }
    return abs(row[ini]- N);
}

void construct() {
    for(int i = 30; i >= 0; i--) {
        for(int j = i-1; j >= 0; j--) {
            ll num = (1 << i) + (1 << j);
            //bitset<32>x(num);
            //cout << x << endl;
            row.pb(num);
            //cout << num << endl;
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    construct();
    while(tc--) {
        ll N;
        cin >> N;
        cout << search(N) << endl;
    }

    return 0;
}

