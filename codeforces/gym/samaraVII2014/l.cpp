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
int pessoas[T];
vector<int> grupo[T];
int maiorDoG[T];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    int k, z;
    for(int i = 0; i < T; i++) pessoas[i] = 1e9; 
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> k >> maiorDoG[i];
        for(int j = 0; j < k; j++) {
            cin >> z;
            grupo[i].pb(z);
            pessoas[z] = min(pessoas[z], maiorDoG[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        int best = 0;
        for(int j = 0; j < grupo[i].size(); j++) 
            best = max(best, pessoas[grupo[i][j]]);
        if(best != maiorDoG[i]) { cout << "Poor memory" << endl; return 0; }
    }

    cout << "Good memory" << endl;
    for(int i = 1; i <= m; i++) cout << pessoas[i] << " ";
    cout << endl;




    return 0;
}

