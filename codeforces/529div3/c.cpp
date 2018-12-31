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
const int T = 2e5 + 10;
int v[T];
int n, k;

bool solve() {
    for(int i = 0; i < k; i++) v[i] = 1;
    int sum = k;
    int i = 0;
    while(sum < n and i < k) {
        if(sum + v[i] <= n) { sum += v[i]; v[i] *= 2; }
        else i++;
    }
    return (sum == n? true : false);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(solve()) {
        cout << "YES" << endl;
        for(int i = 0; i < k; i++)
            cout << v[i] << " ";
        cout << endl;
    } else  cout << "NO" << endl;
    return 0;
}

