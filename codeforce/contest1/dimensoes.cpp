#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M, N, L, C, K;
    cin >> M >> N >> L >> C >> K;

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


    int k = 0;
    int p = 0;
    int cont = 0;

    for(int i = k; i < (C + k) && i < M; ++i)
    {
        if(k == M - 1)
        {
            k = 0;
            p++;
        }
        for(int j = p; j < (L + p) && j < N; ++j)
        {
            sum += matrix[i][j];
            cont++;
        }
        if(cont == C * L) 
        {
            if(sum > maxsum)
            {
                maxsum = sum;
            }
            sum = 0;
            cont = 0;
            k++;
            i = k;
        }

    }

    cout << maxsum << endl;
}


