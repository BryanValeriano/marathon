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

const int T = 11;
int v[T];
int n;

void print(int mask) {
    cout << __builtin_popcount(mask) << endl;
    for(int i = 0; i < n; i++)  
        if(mask & (1 << i)) cout << i+1 << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if(n == 1) { cout << -1 << endl; return 0; }
    for(int i = 0; i < n; i++) cin >> v[i];
    int gol = pow(2,n)-1;

    for(int i = 1; i < gol; i++) {
        int a = 0;
        int b = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1<<j)) a += v[j];
            else b += v[j];
        }
        if(a != b) {
            print(i);
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}

