#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int matrix[1000][1000];
int N, M,fim, passos = INT_MAX;

void backtrack(int i, int j, int qtd)
{
    if(matrix[i][j] == 3) passos = min(passos, qtd);

    else
    {
        if(i+1 < N && i >= 0 && matrix[i+1][j] != 0) 
        {  
            matrix[i][j] = 0;
            backtrack(i+1, j, qtd+1);
            matrix[i][j] = 1;     
        }
        if(j+1 < M && j >= 0 && matrix[i][j+1] != 0) 
        {  
            matrix[i][j] = 0;
            backtrack(i, j+1, qtd+1);
            matrix[i][j] = 1;
        }
        if(i < N && i-1 >= 0 && matrix[i-1][j] != 0) 
        {   
            matrix[i][j] = 0;
            backtrack(i-1, j, qtd+1);
            matrix[i][j] = 1;
        }
        if(j < M && j-1 >= 0 && matrix[i][j-1] != 0) 
        {   
            matrix[i][j] = 0;
            backtrack(i, j-1, qtd+1);
            matrix[i][j] = 1;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    memset(matrix, 0, sizeof matrix);
    int inicioI, inicioJ;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j] == 2)
            {
                inicioI = i;
                inicioJ = j;
            }
        } 
    backtrack(inicioI,inicioJ,1);
    
    cout << passos << endl;
    
    return 0;
}

