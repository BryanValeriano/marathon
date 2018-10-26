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
const int T = 1e6 + 3;
bool crivo[T];

void pre() {
    crivo[0] = true; crivo[1] = true;
    for(int i = 2; i < T; i++) 
        for(int j = i+i; j < T; j += i) 
            crivo[j] = true;
}
            

int main() {
    ios::sync_with_stdio(false);
    pre();
    int n; cin >> n;
    long double aux;
    long long aux2;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        aux = sqrtl(aux);
        if(aux != floorl(aux)) { cout << "NO" << endl; continue; } 
        aux2 = aux; 
        cout << (!crivo[aux2]? "YES" : "NO") << endl;
    }
    return 0;
}

