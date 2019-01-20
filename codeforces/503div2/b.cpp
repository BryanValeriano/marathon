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
const int T = 1e3 + 10;
int v[T];
int vez[T];

int simulate(int start) {
    memset(vez, 0, sizeof vez); 
    while(vez[start] < 1) {
        vez[start]++;
        start = v[start];
    }
    return start;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) {
        cout << simulate(i) << " ";
    }
    cout << endl;
    return 0;
}

