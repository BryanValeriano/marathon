#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int matrix[N][N];

    int sums[(N+N) + 2];

    for(int i = 0; i < (N+N + 2); i++)
    {
        sums[i] = 0;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
            sums[i] += matrix[i][j];
            sums[j + N] += matrix[i][j];
            if(i == j)
            {
                sums[(N + N)] += matrix[i][j];
            }
            if(i + j == N - 1)
            {
                sums[(N + N) + 1] += matrix[i][j];
            }
        }
    }
    
    for(int i = 0; i < (N+N) + 2; i++)
    {
        if(sums[i] != sums[0])
        {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << sums[0] << endl;
}
