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
    int n; cin >> n;
    int maxi = 1;
    int cont = -1;
    int aux;
    int last = 0;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        if(aux >= last) cont++;
        else cont = 0;
        last = aux;
        if(cont + 1 > maxi) maxi = cont + 1;
    }
    cout << maxi << endl;
    return 0;
}

