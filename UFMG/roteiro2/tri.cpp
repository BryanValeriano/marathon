#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int N;
int val[100000];
int soma[100000];


bool buscaBin(ll i, int ini, int fim){
    
    int mid = (ini+fim)/2;

    if(ini>fim) return false;

    if(i==soma[mid]) return true;
    if(i<soma[mid]) return buscaBin(i, ini, mid-1);
    else return buscaBin(i, mid+1, fim);
}

bool buscaTriangulo(ll i, ll maxx){
    return (buscaBin(soma[i]+maxx, 0, N-1) && buscaBin(soma[i]+2*maxx, 0, N-1)) /*&& buscaBin(soma[i]+3*maxx, 0, N-1)*/;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    
    int sum;
    int length;
    int pontos;
    int cont;
    cin >> N;

    while(N)
    {
        val[0] = 1;
        soma[0] = 1;
        sum = 0;
        cont = 0;
        for(int i = 1; i < N; i++)
        {
            cin >> val[i];
            sum += val[i];
            soma[i] = sum;
        }
        length = sum/3;
        for(ll i = 0; i < N/3; i++)
        {
            if(buscaTriangulo(i, length)) cont++; 
        }
        
        cout << cont << endl;
        cin >> N;
    }
      
    return 0;
}

