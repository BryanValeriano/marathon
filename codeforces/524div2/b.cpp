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
    int q; cin >> q;
    while(q--) {
        ll l, r;
        cin >> l >> r;
        ll parL, imparL, parR, imparR;
        parR = imparR = r;
        parL = imparL = l;
        if(l & 1) parL++;
        else imparL++;
        if(r & 1) parR--;
        else imparR--;

        ll qtdPar = ((parR - parL) >> 1) + 1;
        ll qtdImpar = ((imparR - imparL) >> 1) + 1;

        cout << (qtdPar*(parL + parR)/2) - (qtdImpar*(imparL + imparR)/2) << endl;
    }
    return 0;
}

