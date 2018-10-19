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

bool cmp(const int &a, const int &b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> row;
    int aux;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        sum += aux;
    }
    for(int i = 0; i < n; i++) {
        cin >> aux;
        row.pb(aux);
    }
    sort(row.begin(), row.end(), cmp);
    ll maxi = row[0] + row[1];
    cout << (maxi >= sum? "YES" : "NO") << endl;

    return 0;
}

