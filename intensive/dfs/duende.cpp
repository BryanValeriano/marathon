#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int matx[10][10];
int N, M;
int caminho = 1e5 + 5;

void dfs(int inI, int inJ, int passos)
{
    if(matx[inI][inJ] == 0) {caminho = min(caminho, passos); return;} 
    if(matx[inI][inJ] == 2) return;
    
    int sinal;
    matx[inI][inJ] = 2;

    if(inI + 1 < N){sinal = matx[inI + 1][inJ]; dfs(inI + 1, inJ, passos + 1); matx[inI + 1][inJ] = sinal;} 
    if(inI - 1 >= 0){sinal = matx[inI - 1][inJ]; dfs(inI - 1, inJ, passos + 1); matx[inI - 1][inJ] = sinal;}
    if(inJ + 1 < M){sinal = matx[inI][inJ + 1]; dfs(inI, inJ + 1, passos + 1); matx[inI][inJ + 1] = sinal;}
    if(inJ - 1 >= 0){sinal = matx[inI][inJ - 1]; dfs(inI, inJ - 1, passos + 1); matx[inI][inJ - 1] = sinal;}
}

int main(){
    ios_base::sync_with_stdio(false);
    int inI, inJ;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            cin >> matx[i][j];
            if(matx[i][j] == 3){inI = i; inJ = j;}
        }
    
    dfs(inI, inJ, 0);
    cout << caminho << endl;
    
    
    return 0;
}

