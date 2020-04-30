#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+2;
char mat[T][T];

int main() {
    ios_base::sync_with_stdio(false);

    for(int i = 1; i < T; i++)
        for(int j = 1; j < T; j++)
            mat[i][j] = 'N';

    int k; cin >> k;

    if(k&1) {
        mat[1][3] = mat[3][2] = 'Y';
        k--;
    }
    if(k) {


    }




    return 0;
}

