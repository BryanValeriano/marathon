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
    int n, d;
    cin >> n >> d;
    vector< pair<int,int> > row;
    int tmp = d;
    for(int i = 0; i < n-d; i++) 
        row.pb(mk(i, tmp++));

    return 0;
}

