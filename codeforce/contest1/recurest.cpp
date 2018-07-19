#include <bits/stdc++.h>

using namespace std;

int matrix[305][305];

int recurest0(int M, int n, int l, int c, int k, int cont, int matrix[305][305]);
int recurest1(int M, int n, int l, int c, int k, int cont, int matrix[305][305]);
int recurest2(int M, int n, int l, int c, int k, int cont, int matrix[305][305]);
int recurest3(int M, int n, int l, int c, int k, int cont, int matrix[305][305]);
int recurest4(int M, int n, int l, int c, int k, int cont, int matrix[305][305]);

int main()
{
    int N, M, L, C, K;

    cin >> N >> M >> L >> C >> K;
    int cont = 1;
    char aux;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> aux;
            if( aux == '#')  matrix[i][j] = -2;
            else matrix[i][j] = -1;
        }
    }
    
    if(matrix[L][C] != -2 && matrix[L][C] < 0 && L >= 0 && L < N && cont <= K)
        recurest0(M, N, L, C, K, cont, matrix[305][305]);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(matrix[i][j] == -1) cout << "." << " ";
            else if(matrix[i][j] == -2) cout << "#" << " ";
            else  cout << matrix[i][j] << " ";  cout << endl;
        }
    }

}

recurest0(int M, N, L, C, K, cont, matrix[N][])
{
    matrix[L][C] = cont;
    cont++;
    
    recurest1(M, N, (L - 1), C, K, cont, matrix[305][305]);
    
    recurest2(M, N, L, (C + 1), K, cont, matrix[305][305]);
    
    recurest3(M, N, (L + 1), C, K, cont, matrix[305][305]);

    recurest4(M, N, L, (C - 1), K, cont, matrix[305][305]);
}

recurest1(M, N, (L - 1), C, K, cont, matrix[305][305])
{
    matrix[L][C] = cont;
    cont++;

    if(matrix[L - 1][C] != -2 && matrix[L - 1][C] < 0 && (L - 1) >= 0 && (L -1) < N && cont <= K)
        recurest1(M, N, (L - 1), C, K, cont, matrix[305][305]);
}

recurest2(M, N, L, (C + 1), K, cont, matrix[305][305])
{
    matrix[L][C] = cont;
    cont++;

    if(matrix[L][C + 1] != -2 && matrix[L][C + 1] < 0 && (C + 1) >= 0 && (C + 1) < M && cont <= K)
        recurest2(M, N, L, (C + 1), K, cont, matrix[305][305]);
}

recurest3(M, N, (L + 1), C, K, cont, matrix[305][305])
{
    matrix[L][C] = cont;
    cont++;

    if(matrix[L + 1][C] != -2 && matrix[L + 1][C] < 0 && (L + 1) >= 0 && (L + 1) < N && cont <= K)
        recurest3(M, N, (L + 1), C, K, cont, matrix[305][305]);
}

recurest4(M, N, L, (C - 1), K, cont, matrix[N][])
{
    matrix[L][C] = cont;
    cont++;

    if(matrix[L][C - 1] != -2 && matrix[L][C - 1] < 0 && (C - 1) >= 0 && (C - 1) < M && cont <= K)
        recurest4(M, N, L, (C - 1), K, cont, matrix[305][305]);
}
 


