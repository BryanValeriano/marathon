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

const int T = 100;
int mat[T][T];
int x[3][2];
int y[3][2];

vector<int> v;
map<int,int> id;

void col(int x, int x1, int x2, int y1, int y2) {
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            mat[i][j] = x;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 3; i++) {
        cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
        x[i][0] *= 2;
        y[i][0] *= 2;
        x[i][1] *= 2;
        y[i][1] *= 2;
        v.pb(x[i][0]);
        v.pb(x[i][0]-1);
        v.pb(x[i][0]+1);
        v.pb(x[i][1]);
        v.pb(x[i][1]-1);
        v.pb(x[i][1]+1);

        v.pb(y[i][0]);
        v.pb(y[i][0]-1);
        v.pb(y[i][0]+1);
        v.pb(y[i][1]);
        v.pb(y[i][1]-1);
        v.pb(y[i][1]+1);
    }

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for(int i = 0; i < v.size(); i++) id[v[i]] = i;

    col(1, id[x[0][0]], id[x[0][1]], id[y[0][0]], id[y[0][1]]);
    for(int i = 1; i < 3; i++) {
        col(2, id[x[i][0]], id[x[i][1]], id[y[i][0]], id[y[i][1]]);
    }


    for(int i = 0; i < T; i++)
        for(int j = 0; j < T; j++)
            if(mat[i][j] == 1) {
                cout << "YES" << endl;
                return 0;
            }

    cout << "NO" << endl;

    return 0;
}

