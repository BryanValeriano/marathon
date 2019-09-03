#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

bool isprime(int x) {
    for(int i = 2; i*i <=x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    if(! isprime(m)) { cout << "NO" << endl; return 0; }
    else 
        for(int i = n+1; i < m; i++)
            if(isprime(i)) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;

    return 0;
}

