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
const int T = 2e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int depth = 0;
    int symbols = 0;
    int maxi = 0;
    int maxi2 = 0;
    int ini = -1;
    int ini1;
    int ini2;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == 1) depth++;
        else depth--;
        if(depth > maxi) { maxi = depth; ini1 = i+1; }
        if(depth == 0) ini = i;
        if(depth >= 1) symbols++;
        else symbols = 0;
        if(symbols > maxi2) { maxi2 = symbols+1; ini2 = ini + 2; }
    }
    cout << maxi << " " << ini1 << " " << maxi2 << " " << ini2 << endl;


    return 0;
}

