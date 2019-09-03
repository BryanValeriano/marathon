#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main()
{
    int N, K, soma = 0;
    int resp = 0;
    int maxx = INF;
    cin >> N >> K;
    int row[N];
    for(int i = 0; i < N; i++)
        cin >> row[i];
    for(int i = 0; i < K; i++)
    {
        soma += row[i];
    }
    maxx = soma;
    resp = 0;
    for(int i = 1; i <= N - K; i++)
    {
        soma -= row[i -1];
        soma += row[i + K -1];
        if(soma < maxx)
        {
            maxx = soma;
            resp = i;
        }
    }
    cout << resp + 1 << endl; 
    
    return 0;
}

