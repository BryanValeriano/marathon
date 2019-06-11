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

const int T = 3e5 + 5;
ll v[T];
ll seg[4*T];
int n;
ll k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = n-1; i >= 1; i--) v[i] += v[i+1];
    build(1,1,n);
    k--;

    while(k) {


    return 0;
}

