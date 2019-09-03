#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int n = 1e2;
const int t = 1e3;

int main() {
    ios::sync_with_stdio(false);
    cout << t << endl;
    for(int i = 1; i <= t; i++) {
        for(int j = i; j < n+i; j++) {
            cout << i << endl;
        }
    }
    cout << endl;
    return 0;
}

