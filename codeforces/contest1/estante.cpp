#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, L, C, K;

    cin >> N >> M >> L >> C >> K;
    int cont = 1;
    K += cont;    
    char aux;

    int matrix[N][M];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> aux;
            if( aux == '#')
            {
                matrix[i][j] = -2;
            }
            else
            {
                 matrix[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < K; i++)
    {
        if(matrix[L][C] != -2)
        {
            matrix[L][C] = cont;
            cont++;
            while(matrix[L - 1][C] != -2 && L >= 0 && L < N && cont <= K)
            {
                L--;
                matrix[L][C] = cont;
                cont++;
            }
            while(matrix[L][C + 1] != -2 && C >= 0 && C < M && cont <= K)
            {  
                C++;
                matrix[L][C] = cont;
                cont++;
            }
            while(matrix[L + 1][C] != -2 && L >= 0 && L < N && cont <= K)
            {
                L++;
                matrix[L][C] = cont;
                cont++;
            }
            while(matrix[L][C - 1] != -2 && C >= 0 && C < M && cont <= K)
            {
                C--;
                matrix[L][C] = cont;
                cont++;
            }

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

