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
typedef pair<double, ii> node;
 
ll mat[50][50];
int n, m;
ll k;
 
priority_queue<node, vector<node> > q;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
 
    for(int j = 0; j < m; j++) cin >> mat[0][j];
    sort(mat[0], mat[0]+m); 

    for(int i = 1; i < n; i++) 
        for(int j = 0; j < m; j++) 
            mat[i][j] = mat[i-1][j];
 
    ll tempo = 0; 
    int pt = 0;
    for(int i = 0; i < n; i++) q.emplace((double)1/(double)mat[i][0], mk(i,0) );
    
    while(!q.empty()) {
        node at = q.top();
        int i = at.se.fi;
        int j = at.se.se;
 
        q.pop();
        if(tempo + mat[i][j] > k) break; 
        cout << i << " " << j << endl;
        tempo += mat[i][j]; pt += 1 + (j == m-1);
        if(j + 1 < m) q.emplace((double)(1 + (j == m-2))/(double)mat[i][j+1], mk(i,j+1));
    }
    cout << pt << endl; 
    return 0;
}
 
