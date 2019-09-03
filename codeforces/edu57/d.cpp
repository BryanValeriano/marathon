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
const int T = 1e5 + 10;
int cost[T];
int n; string s;
int h,a,r,d;

void solve() {
    for(int i = 0; i < n; i++) {
        if(s[i] !

void read() {
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> cost[i];
}

int main() {
    ios::sync_with_stdio(false);
    read();
    solve();
    return 0;
}

