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
    int meio;
    while(fim - ini > 1) {
        meio = (ini + fim)/2;
        if(row[meio] < N) ini = meio;
        else if(row[meio] > N) fim = meio;
        else {fim = meio; break;}
    }
    
    if(abs(row[meio] - N) > abs(row[fim] - N) || abs(row[meio] - N) > abs(row[ini] - N)) {
        if(abs(row[fim] - N) < abs(row[ini] - N)) return abs(row[fim] - N);
        else return abs(row[ini] - N);
    }
    return abs(row[meio] - N);
}

void construct() {
    for(int i = 0; i <= 30; i++) {
        for(int j = i+1; j <= 30; j++) {
            ll num = (1 << i) + (1 << j);
            //bitset<64>x(num);
            //cout << x << endl;
            row.pb(num);
            //cout << num << endl;
        } 
    }
    /*
    row.pb(1);
    row.pb(2);
    row.pb(100);
    row.pb(100);
    row.pb(101);
    */
}

int main() {
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    construct();
    sort(row.begin(), row.end());
    while(tc--) {
        ll N;
        cin >> N;
        cout << search(N) << endl;
    }
    return 0;
}

