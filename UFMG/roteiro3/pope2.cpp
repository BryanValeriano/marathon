#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define MAXN 1100

typedef long long ll;

int n; 
pair<int,int> dp[MAXN];
int dp2[MAXN];

//ordena maior resist
bool compareResist(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.fi < j.fi;
}

//ordena menor peso
bool comparePeso(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first > j.first;
}

int empilha(pair<int, int> caixasA[], pair<int, int> caixasB[], int i, int j, int max, int resist)
{  
    cout << i << endl;
    
    //se suportar o peso da caixa mais resistente
    if(dp2[caixasB[i].second] != 1 && resist - dp[caixasB[i].second].first > 0 && i < n)
    {
        //empilhamos ela e vemos qual a menor 
        //resistencia remanescente
        dp2[caixasB[i].second] = 1;
        if(resist - dp[caixasB[i].second].first < caixasB[i].first) resist -= dp[caixasB[i].second].first;
        else resist = caixasB[i].first;
        empilha(caixasA,  caixasB, i + 1, j, max, resist);
    }

    if(i + j > max) max = i + j;

    //se suportar o peso da caixa mais leve
    if(dp2[caixasA[j].second] != 1 && resist - caixasA[j].first > 0 && j < n)
    {
        //empilhamos ela e vemos qual a menor
        //resistencia remanescente
        dp2[caixasA[j].second] = 1;
        if(resist - caixasA[j].first < dp[caixasA[j].second].first) resist -= caixasA[j].first;
        else resist = caixasA[i].first;
        empilha(caixasA,  caixasB, i, j + 1, max, resist);
    }

    if(max < i + j) max = i + j;
    else return max;
}
        
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
   
    pair<int,int> caixasA[n];
    pair<int,int> caixasB[n];
    int peso, resist;

    for(int i = 0; i < n; i++)
    {
        cin >> peso >> resist;
        resist -= peso;
        caixasA[i] = mk(peso, i);
        caixasB[i] = mk(resist, i);
        dp[i] = mk(peso, resist);
    }
    
    sort(caixasA, caixasA + n, compareResist);  
    sort(caixasB, caixasB + n, comparePeso);   
     
    //cout << "b" << endl;

    memset(dp2, 0, sizeof(dp));

    int altura1 = empilha(caixasA, caixasB, 0,  0, 0, MAXN);

    cout << altura1 << endl;

    return 0;
}

