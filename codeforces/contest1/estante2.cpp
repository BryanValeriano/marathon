#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, L, C, K;

    cin >> N >> M >> L >> C >> K;
    int cont = 1;
    char aux;
    int l = L;
    int c = C;
    int move = 0;
    int j = 0;
    int foi = 0;
    int moves[4];

    int matrix[N][M];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> aux;
            if( aux == '#')  matrix[i][j] = -2;
            else matrix[i][j] = -1;
        }
    }

    while(j < 3)
    {
        move = 0;
        if(matrix[L][C] != -2 && matrix[L][C] < 0) 
        {
            matrix[L][C] = cont;
            cont++;
            move++;
            foi = 1; 
        }
        if(foi == 1)
        {
            while(matrix[L - 1][C] != -2 && matrix[L - 1][C] < 0 && (L - 1) >= 0 && (L -1) < N && cont <= K)
            {
                L--;
                matrix[L][C] = cont;
                cont++;
                move++;
                moves[0] = 1;
            }
            while(matrix[L][C + 1] != -2 && matrix[L][C + 1] < 0 && (C + 1) >= 0 && (C + 1) < M && cont <= K)
            {  
                C++;
                matrix[L][C] = cont;
                cont++;
                move++;
                moves[1] = 1;
            }
            while(matrix[L + 1][C] != -2 && matrix[L + 1][C] < 0 && (L + 1) >= 0 && (L + 1) < N && cont <= K)
            {
                L++;
                matrix[L][C] = cont;
                cont++;
                move++;
                moves[2] = 1;
            }
            while(matrix[L][C - 1] != -2 && matrix[L][C - 1] < 0 && (C - 1) >= 0 && (C - 1) < M && cont <= K)
            {
                C--;
                matrix[L][C] = cont;
                cont++;
                move++;
                moves[3] = 1;
            }
        }
        if(move == 0 && j == 2)
        {
            int w = 3;
            while(moves[w] != 1)
            {
               w--;
            }
 
        else if(move == 0)
        {
            L = l;
            C = c;
            j++;        
        }
        else
        {
             j = 0;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(matrix[i][j] == -1) cout << "." << " ";
            else if(matrix[i][j] == -2) cout << "#" << " ";
            else  cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

