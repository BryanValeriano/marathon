#include <iostream>

int main ()
{
    int N;
    std::cin >> N;
    int matrix[N][N];
    int matrix2[N][N];
    int x;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> matrix2[i][j];
            x = matrix[i][j] + matrix2[i][j];
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    } 
