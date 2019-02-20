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

int n;
const int N = 25;
const int T = 500;
const int TT = 1050;
int v[T];
int m[N][N];
int freq[TT];

void espelho(int x, int y) {
    for(int i = 1; i <= 1000; i++) {
        if(freq[i] >= 4) {
            m[x][y] = m[n-x+1][y] = m[x][n-y+1] = m[n-x+1][n-y+1] = i;
            freq[i] -= 4;
            return;
        }
    }
}

void um(int x, int y) {
    for(int i = 1; i <= 1000; i++) {
        if(freq[i] >= 2 and x != y) {
            if(x == (n/2) + 1) m[x][y] = m[x][n-y+1] = i;
            if(y == (n/2) + 1) m[x][y] = m[n-x+1][y] = i;
            freq[i] -= 2;
            return;
        } 
        else if(freq[i] > 0 and x == y) {
            m[x][y] = i;
            freq[i]--;
            return;
        }
    }
}

bool check() {
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            if(m[i][j] == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n*n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            if(m[i][j] == 0) 
                if(!(n&1 and (i == (n/2) + 1 or j == (n/2) + 1))) 
                    espelho(i,j);
    
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            if(m[i][j] == 0) 
                if(n&1 and (i == (n/2) + 1 or j == (n/2) + 1)) um(i,j);

    if(check()) {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    } else cout << "NO" << endl;
                
    //for(int i = 1; i <= n; i++) {
    //    for(int j = 1; j <= n; j++) {
    //        cout << m[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    return 0;
}

