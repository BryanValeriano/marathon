#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e4+3;
vector<int>cit[TAM];
int dev[TAM];

int main()
{
    int n, tanque, aux;
    cin >> n >> tanque;
    for(int i = 0; i < n; i ++)
    {
        cin >> aux;
        dev[i + 1] = aux; 
    }
    
    
    return 0;
}

