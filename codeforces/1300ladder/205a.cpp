#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    pair<int,int>mini;
    int n; cin >> n;
    int aux; cin >> aux;
    int ind = 0;
    mini = mk(aux, 0);
    for(int i = 1; i < n; i++) {
        cin >> aux;
        if(aux < mini.fi) { mini = mk(aux, 0); ind = i; }
        else if(aux == mini.fi) mini.sec++;
    }
    if(mini.sec == 0) cout << ++ind;
    else cout << "Still Rozdil";
    cout << endl;
    return 0;
}

