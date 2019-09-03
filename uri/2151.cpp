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
    int TC, M, N, X, Y;
	int cont = 0;
    cin >> TC;
    while(TC--)
    {
        cout << "Parede " << ++cont << ":" << endl;
        cin >> M >> N >> X >> Y;
        int matrix [M + 1][N + 1];
        for(int i = 1; i <= M; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                cin >> matrix[i][j]; 
                if(10 - max(abs(X - i), abs(Y - j)) > 0)
                    matrix[i][j] += 10 - max(abs(X - i), abs(Y - j)); 
                else matrix[i][j] += 1; 
                cout << matrix[i][j];
                if(j + 1 <= N) cout << " ";
            }
            cout << endl;
        }
    }
    
    
    return 0;
}

