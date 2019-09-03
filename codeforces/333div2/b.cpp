#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 3;
int row1[T];
int row2[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int aux;
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        if(row1[aux] == 0) row1[aux] = i;
        if(row2[aux] < i) row2[aux] = i;
    }
    int maxx = 0;

    for(int i = 1; i <= n; i++) {
        cout << row1[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++) {
        cout << row2[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++) {
        maxx = max(maxx, row2[i] - row1[i]);
    }
    cout << maxx << endl;

    return 0;
}

