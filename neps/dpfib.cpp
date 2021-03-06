#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define MAXN 1000100

int n, dp[MAXN]; // declaro n e o vetor auxiliar

typedef long long ll;

int fib(int x) // declaro a função int fib(int x)
{  
    // se já calculei, alguma vez, o valor de fib(x)
    if(dp[x]!=-1) return dp[x]; // retorno o que está salvo em dp[x]
        
    // se não, calculo a função normalmente
    if(x==0) return 0; // se x=0, retorn 0
    if(x==1) return 1; // se x=1, retorn 1
                
    // se não era nenhum dos casos base
    return dp[x] = fib(x-1) + fib(x-2); // calculo o valor de fib(x) e salvo em dp[x]
}

int main()
{
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp)); // faço todos as posições de dp receberem o valor -1
                              
    cin >> n; // leio o valor de n
                              
    cout << fib(n) << "\n"; // e imprimo o valor de fib(n)
                                  
    return 0;
 
}

