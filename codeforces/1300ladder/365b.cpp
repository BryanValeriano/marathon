#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 5;
int row[T];
int row2[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> row[i];
    
    int maxi = 0;
    int cont = 0;
    for(int i = 2; i < n; i++) {
        if(row[i] == row[i-1] + row[i-2]) {
            cont++;
        } else {
            maxi = max(maxi,cont);
            cont = 0;
        }
    }
        
    maxi = max(maxi,cont);
    if(n == 1) maxi += 1; 
    else maxi += 2;
    cout << maxi << endl;
    return 0;
}

