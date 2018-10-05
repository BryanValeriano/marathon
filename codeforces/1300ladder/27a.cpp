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
    int n;
    cin >> n;
    int row[n];
    for(int i = 0; i < n; i++) {
        cin >> row[i];
    }
    sort(row, row + n);
    if(row[0] != 1) { cout << 1 << endl; return 0; }
    for(int i = 1; i < n; i++) {
        if(row[i] - row[i-1] > 1) {
            cout << row[i-1] + 1 << endl;
            return 0;
        }
    }
    cout << row[n-1] + 1 << endl;
    return 0;
}
