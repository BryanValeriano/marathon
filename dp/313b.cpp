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
    string row;
    getline(cin, row);
    int roww[row.size()];
    int cont = 0;
    roww[0] = cont;
    for(int i = 1; i < row.size(); i++)
    {
        if(row[i] == row[i-1])
        {
            cont++;
            roww[i] = cont;
        }
        else roww[i] = cont;
    }
    int N, x, y;
    cin >> N;
    while(N--)
    {
        cin >> x >> y;
        cout << roww[y - 1] - roww[x - 1] << endl;
    }
        
    return 0;
}

