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
    int n, k; cin >> n >> k;
    int fim = n;
    for(int i = 0; i < k; i++)
        cout << fim-- << " ";
    for(int i = k; i < n; i++) 
        cout << i - k + 1 << " ";
    cout << endl;
    return 0;
}

