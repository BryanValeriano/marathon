#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M, N, L, C;
    cin >> M >> N >> L >> C;

    int matrix[M][N];
    int sum = 0;
    int maxsum = 0;


    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    int fim = L;
    int fim2 = C;
    int inicio = 0;
    int inicio2 = 0;

    for(int p = inicio; inicio <= (M - L + 1) && fim <= M; inicio++, fim++)
    {
        for(int k = inicio2; inicio2 <= (N - C + 1) && fim2 <= N; inicio2++, fim2++)
        {    
            for(int i = inicio; i < fim; i++)
            {
                for(int j = inicio2; j < fim2; j++)
                {
                    sum += matrix[i][j];
                }
            }
            if( sum > maxsum)
            {
                maxsum = sum;
                sum = 0;
            }else{
                sum = 0;
            }
        }
        inicio2 = 0;
        fim2 = C;
    }



    cout << maxsum << endl;
}

