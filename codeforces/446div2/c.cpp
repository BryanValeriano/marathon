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

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int row[n];
    bool flag = false;
    int tmp = 0;
    for(int i = 0; i < n; i++) { 
        cin >> row[i];
        if(row[i] == 1) tmp++;
    }
    if(tmp >= 1) { cout << n - tmp << endl; return 0; }
    int last; 
    int dist = INF;
    for(int i = 0; i < n; i++) {
        last = row[i]; 
        for(int j = i + 1; j < n; j++) {
            last = __gcd(last, row[j]);
            if(last == 1) dist = min(dist, j - i);
        }
    }
    cout << (dist == INF? -1 : dist + n-1) << endl;
    return 0;
}

