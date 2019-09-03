#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int mat[4][4];
int cod[4][4];

bool dentro(int i, int j) {
    return(i >= 0 and j >= 0 and i < 3 and j < 3);
}

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };


void propaga(int i, int j) {
    mat[i][j] = 1 - mat[i][j];
    for(int k = 0; k < 4; k++) {
        int ii = i + mov[k][0];
        int jj = j + mov[k][1];
        if(dentro(ii,jj)) mat[ii][jj] = 1 - mat[ii][jj];
    }
}

int main() {
    ios::sync_with_stdio(false);
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) {
            cin >> cod[i][j];
            mat[i][j] = 1;
        }
     
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) 
            if(cod[i][j]&1) propaga(i,j);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}

