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

const int T = 1e5 + 5;
bool v[T];
int n;

bool ciclo(int ini, int passo) {
    while(1) {
        if(!v[ini]) return false;
        ini += passo;
        if(ini%n != ini) return v[ini%n];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 1; i < n; i++) 
        if(n%i == 0 and n/i >= 3) 
            for(int j = 0; j < i; j++)
                if(ciclo(j,i)) { cout << "YES" << endl; return 0; }
            
    cout << "NO" << endl;

    return 0;
}

