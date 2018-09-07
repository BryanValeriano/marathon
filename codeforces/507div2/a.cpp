#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    int n;
    int c[2];
    cin >> n >> c[0] >> c[1];
    int row[n];
    for(int i = 0; i < n; i++)
        cin >> row[i];
    int mini = min(c[0],c[1]);
    int ini = 0;
    int fim = n-1;
    int cost = 0;
    while(ini <= fim) {
        if(row[ini] != row[fim] && row[ini] != 2 && row[fim] != 2) {
            cout << -1 << endl; return 0;
        }
        if(row[ini] == row[fim] && row[ini] == 2)
            if(ini != fim)
                cost += 2*mini; 
            else cost += mini;
        else if(row[ini] != row[fim] && row[ini] != 2) 
            cost += c[row[ini]]; 
        else if(row[ini] != row[fim] && row[fim] != 2)
            cost += c[row[fim]];
        ini++; fim--;
    }
    cout << cost << endl;
    return 0;
}

