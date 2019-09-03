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
map<int,int>track;

int main() {
    ios::sync_with_stdio(false);
    int meio = 2e5 + 5;
    int dir, esq;
    esq = meio;
    dir = meio + 1;
    int q; cin >> q;
    char op; int ind;
    while(q--) {
        cin >> op >> ind;
        if(op == 'L') {
            track[ind] = esq;
            esq--;
        }
        else if(op == 'R') {
            track[ind] = dir;
            dir++;
        }
        else if(op == '?') 
            cout << min( (dir - track[ind])-1, (track[ind] - esq)-1 ) << endl;
    }

    return 0;
}

