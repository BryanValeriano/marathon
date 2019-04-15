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

const int T = 50;
int mat[T][T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int ini = 1; 
    int degrau = -1;
    int l;
    int r;

    for(int i = 1; i <= n; i++) {
        if(i <= n/2 + 1) degrau += 2;
        else degrau -= 2;
        l = (n/2 + 1) - (degrau/2);
        r = (n/2 + 1) + (degrau/2);
        for(int j = 1; j <= n; j++) 
            if(j >= l and j <= r)
                mat[i][j] = ini, ini+= 2;
    }

    ini = 2;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!mat[i][j]) mat[i][j] = ini, ini+=2;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}

