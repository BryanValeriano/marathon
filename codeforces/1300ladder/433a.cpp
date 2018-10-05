#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

bool cmp(const int &a, const int &b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int sum1 = 0;
    int sum2 = 0;
    int aux;
    vector<int>row;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        row.pb(aux);
    }
    sort(row.begin(), row.end(), cmp);
    for(auto id : row) {
        if(sum1 <= sum2) sum1 += id;
        else sum2 += id;
    }
    cout << (sum1 == sum2? "YES" : "NO") << endl;

    return 0;
}

