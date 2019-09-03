#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
bool gemeos(int row[], int TAM);

int passos;

int main()
{
    int TAM = 1024;
    int row[TAM];
    int cont = -20;
    for(int i = 0; i < TAM; i++)
        row[i] = ++cont;

    row[10] = 10;
    for(int i = 11; i < TAM; i++)
        row[i] = ++cont;

    gemeos(row, TAM)? cout << "tem" << endl : cout << "nao tem" << endl;
    cout << passos << endl;

    return 0;
}

bool gemeos(int row[], int TAM)
{
    int fim = TAM;
    int ini = 0;
    while(fim - ini > 1)
    { 
        passos++;
        int meio = (ini + fim)/2;
        if(row[meio] == meio) return true;
        else if(row[meio] < meio) ini = meio;
        else fim = meio;
    }
    return false;
}

