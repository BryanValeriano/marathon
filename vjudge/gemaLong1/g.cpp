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

string a,b,c;
// 0   1    2    3    4    5
//abc acb, bac, bca, cab, cba;

int build(int op) {
    string x;
    string y;
    string z;

    int meio = 0, fim = 0;

    if(op <= 1) x = a; 
    else if(op <= 3) x = b; 
    else x = c;


    if(op == 2 or op == 4) y = a;
    else if(op == 0 or op == 5) y = b;
    else y = c;

    while(meio < y.size() and meio < x.size() and
        y[meio] == x[x.size()-meio-1]) meio++;

    for(int i = meio; i < y.size(); i++) x += y[i];

    if(op == 3 or op == 5) z = a;
    else if(op == 1 or op == 4) z = b;
    else z = c;

    while(fim < z.size() and fim < x.size() and
        z[fim] == x[x.size()-fim-1]) fim++;
    
    for(int i = fim; i < z.size(); i++) x += z[i];

    return x.size();
}

int main() {
    ios::sync_with_stdio(false);

    while(cin >> a) {
        cin >> b >> c;
        int ans = INF;
        for(int i = 0; i < 6; i++) 
            ans = min(ans,build(i));
        cout << ans << endl;
    }

    return 0;
}

