#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define MAX 8*8

typedef long long ll;
int board[8][8];
int sum, maxsum;
int tabuleiro[8];

bool place(int coluna, int linha)
{
    for(int prev = 0; prev < coluna; prev++)
        if(tabuleiro[prev] == linha || abs(prev - coluna) == abs(tabuleiro[prev] - linha))
            return false;
    return true;
}

void calc(int coluna)
{
    if(coluna == 8)
    {
        sum = 0;
        for(int i = 0; i < 8; i++)
            sum += board[i][tabuleiro[i]];
        if(sum > maxsum) maxsum = sum;
    }

    for(int i = 0; i < 8; i++)
    {
        if(place(coluna, i))
        {
            tabuleiro[coluna] = i;
            calc(coluna + 1);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    while(N > 0)
    {
        N--;    
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                cin >> board[i][j];
            }
        }
        maxsum = 0;
        memset(tabuleiro, 0, sizeof(tabuleiro));

        calc(0);
        
        cout << setw(5) << maxsum << endl;
    }
    
    return 0;
}

