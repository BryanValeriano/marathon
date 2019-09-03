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
const int T = 9;
char row[T][T];
vii white;
vii black;

int testA(int a, int b) {
    int cont = 1;
    while(row[a-cont][b] == '.' && a-cont > 1) 
        cont++;
    return (a - cont == 1 && row[a-cont][b] == '.'? cont : INF);
}

int testB(int a, int b) {
    int cont = 1;
    while(row[a+cont][b] == '.' && a+cont < 8) 
        cont++;
    return (a + cont == 8 && row[a+cont][b] == '.'? cont : INF);
}

int main() {
    ios::sync_with_stdio(false);
    for(int i = 1; i <= 8; i++) 
        for(int j = 1; j <= 8; j++) {
            cin >> row[i][j];
            if(row[i][j] == 'W')
                white.eb(i,j);
            else if(row[i][j] == 'B')
                black.eb(i,j);
        }
    int minA = INF;
    int minB = INF;

    for(int i = 0; i < white.size(); i++) 
        minA = min(minA, testA(white[i].fi, white[i].se));

    for(int i = 0; i < black.size(); i++) 
        minB = min(minB, testB(black[i].fi, black[i].se));

    cout << (minA <= minB? "A" : "B") << endl;

    return 0;
}

