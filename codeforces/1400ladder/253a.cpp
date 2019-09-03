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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m; cin >> n >> m;

    int b = 0;
    int g = 0;
    for(int i = 1; i <= n+m; i++) {
        if(i % 2 == 0) {
            if(n < m) { 
                if(b < n) { cout << "B"; b++; }
                else { cout << "G"; g++; }
            } else {
                if(g < m) { cout << "G"; g++; }
                else { cout << "B"; b++; }
            }
        } else {
            if(n < m) {
                if(g < m) { cout << "G"; g++; }
                else { cout << "B"; b++; }
            } else {
                if(b < n) { cout << "B"; b++; }
                else { cout << "G"; g++; }
            }
        }
    }       
    cout << endl;

    return 0;
}

