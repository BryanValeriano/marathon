#include <bits/stdc++.h>

using namespace std;

void insert(int &matrix, int N, int M);

int main()
{
    int N;
    int M;
    cin >> N >> M;

    int matrix[N][M]

    insert(&matrix, N, M);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void insert(int *mat, int N, int M)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
