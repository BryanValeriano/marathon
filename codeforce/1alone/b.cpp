#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int n, k;
int board[105][105];
int sinal1, sinal2;

void naval()
{
    for(int inicioL = 0; inicioL + k < n; inicioL++)
    {
            for(int i = 0; i < inicioL + k; i++)
                if(board[inicioL][i] == -1)
                    sinal2 = 1;

            for(int j = 0; j < inicioL + k; j++)
                if(board[j][inicioL] == -1)
                    sinal2 = 1;
            

            if(sinal1 == 0)
            {
                for(int tmp = 0; tmp < n; tmp++)     
                    for(int i = inicioL; i < k; i++)
                    {
                        board[tmp][i] += 1;
                    }
            }
            if(sinal2 == 0)
            {
                for(int tmp = 0; tmp < n; tmp++)     
                    for(int i = inicioL; i < k; i++)
                    {
                        board[i][tmp] += 1;
                    }
            }   
            sinal1 = sinal2 = 0;

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int x, y, max;
    x = y = max = 0;
    char symbol;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> symbol;
            if(symbol == '#') board[i][j] = -1;
            else board[i][j] = 0;
        }

    int inicioL = 0;
    if(inicioL + k <= n)
        naval();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] > max)
            {
                max = board[i][j];
                x = i;
                y = j;
            }

    cout << x << " " << y << endl;
    return 0;
}

