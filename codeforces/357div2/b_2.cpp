#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 1e9;
int n;
int x = 1234567;
int y = 123456;
int z = 1234;
const int tama = 1e3 + 10;
const int tamb = 1e5 + 10;
int dp[tama][tamb];

bool flag = false;

void brute(int num, int a, int b) {
    if(num == n) flag = true;
    if(num > n or flag) return;
    int t = n - num;
    if(t % x == 0) flag = true;
    int &r = dp[a][b];
    if(r != -1) return;
    r = num;
    brute(num + y, a, b+1);
    brute(num + x, a+1, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    memset(dp, -1, sizeof dp);
    brute(0,0,0);
    
    cout << (flag? "YES" : "NO") << endl;
    return 0;
}

