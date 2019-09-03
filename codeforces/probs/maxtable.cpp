#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    int n; 
    cin >> n;
    int table[n][n];
    for(int i = 0; i < n; i++)
    {
        table[i][0] = 1;
        table[0][i] = 1;
    }

    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            table[i][j] = table[i-1][j] + table[i][j-1];
    
    cout << table[n-1][n-1] << endl;
    
    return 0;
}

