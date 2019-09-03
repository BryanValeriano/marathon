#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int row[4];
    for(int i = 0; i < 4; i++) {
        cin >> row[i];
    }
    int d; cin >> d;
    int resp = 0;
    for(int i = 1; i <= d; i++) {
        for(int j = 0; j < 4; j++) {
            if(i % row[j] == 0) { resp++; break; } 
        }
    }
    cout << resp << endl;
    return 0;
}

