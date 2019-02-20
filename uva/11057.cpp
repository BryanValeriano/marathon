#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n) {
        int x, money;
        map<int,int> track;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(!track.count(x)) track[x] = 1;
            else track[x]++;
        }
        cin >> money;
        int a,b,dif;
        a = 0; b = INF; dif = INF;
        for(auto it : track) {
            if(money - it.fi < 0) break;
            if(track.count(money - it.fi)) {
                if(money-it.fi == it.fi and it.se < 2) continue;
                if(abs((money - it.fi) - it.fi) < dif) {
                    dif = abs(money - it.fi) - it.fi;
                    a = it.fi;
                    b = money - it.fi;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << a << " and " << b << "." << endl << endl;
    }

    return 0;
}

