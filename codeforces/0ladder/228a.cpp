#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int row[4];
    for(int i = 0; i < 4; i++) 
        cin >> row[i];
    int cont = 0;
    int smurf = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            if(row[i] == row[j]) {
                cont++;
                row[j] = --smurf;
            }
        }
    }
    cout << cont << endl;
    return 0;
}

