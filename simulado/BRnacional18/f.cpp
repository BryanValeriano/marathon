#include<bits/stdc++.h>
#define __int128_t unsigned long long
using namespace std;
 
int pos[11];
int vis[11][101];
int prox[11][101];
 
int sz[11];
int mark[11][101];
 
int N, M;
int bestid;
__int128_t best = -1, atual;
 
bitset<101> bit1, bit2;
 
map<int, int> Mapa;
 
__int128_t inv(__int128_t a, __int128_t b)
{
    __int128_t c = a%b;
    for(int i = 1; i < b; i++)
        if((c*i)%b == 1)
            return i;
    return 0;
}
 
 
__int128_t mult(__int128_t x, __int128_t n, __int128_t m)
{
    __int128_t a = 0, b = x % m;
    for(; n > 0; n >>= 1)
    {
        if (n & 1)
            a = (a + b) % m;
        b = (b << 1) % m;
    }
 
    return a % m;
}
 
bool chineseremainder()
{
    vector< pair<int, int> > vet[5];
    for(auto it = Mapa.rbegin(); it != Mapa.rend(); it++)
    {
        if(it->first % 2 == 0)
            vet[1].push_back(*it);
        else if(it->first % 3 == 0)
            vet[2].push_back(*it);
        else if(it->first % 5 == 0)
            vet[3].push_back(*it);
        else if(it->first % 7 == 0)
            vet[4].push_back(*it);
        else
            vet[0].push_back(*it);
    }
    for(int k = 1; k < 5; k++)
    {
        if(vet[k].size())
        {
            for(int i = 1; i < (int)vet[k].size(); i++)
            {
                if(vet[k][0].second%vet[k][i].first != vet[k][i].second)
                    return 0; 
            }
            vet[0].push_back(vet[k][0]);
        }
    }
    __int128_t total = 1, aux;
    atual = 0;
    for(int i = 0; i < (int)vet[0].size(); i++)
    {
        total *= vet[0][i].first;
    }
    for(int i = 0; i < (int)vet[0].size(); i++)
    {
        aux = total/vet[0][i].first;
        atual = (atual+mult(vet[0][i].second*(inv(aux, vet[0][i].first))%total,aux, total))%total;
    }
 
    return 1;
}
 
bool solve(int x)
{
    int d;
    Mapa.clear();
    for(int i = 0; i < N; i++)
    {
        if(sz[i] != 1)
        {
            int z = mark[i][x];
            int y = sz[i];
            for(int j = 2; j*j <= y; j++)
            {
                if(y%j == 0)
                {
                    d = 1;
                    while(y % j == 0)
                    {
                        y /= j;
                        d *= j;
                    }
                    if(!Mapa.count(d))
                        Mapa[d] = z%d;
                    else if(Mapa[d] != z%d)
                        return 0;
                }
            }
            if(y > 1)
            {
                d = y;
                if(!Mapa.count(d))
                    Mapa[d] = z%d;
                else if(Mapa[d] != z%d)
                    return 0;
            }
        }
    }
    return chineseremainder();
}
 
int main()
{
    int mask = 0;
    __int128_t val = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &pos[i]);
        for(int j = 1; j <= M; j++)
            scanf("%d", &prox[i][j]);
    }
    while(mask != ((1 << N)-1))
    {
        int f = 1;
        for(int i = 1; i < N; i++)
            f &= (pos[i] == pos[0]);
        if(f)
        {
            return !printf("%d %llu\n", pos[0], val);
        }
        for(int i = 0; i < N; i++)
        {
            if(vis[i][pos[i]])
                mask |= (1 << i);
            vis[i][pos[i]] = 1;
            pos[i] = prox[i][pos[i]];
        }
        val++;
    }
    bit1.reset();
    for(int i = 1; i <= M; i++)
        bit1.set(i);
    for(int i = 0; i < N; i++)
    {
        int k = 0;
        mark[i][pos[i]] = k++;
        bit2.reset();
        bit2.set(pos[i]);
        int aux = pos[i];
        pos[i] = prox[i][pos[i]];
        while(aux != pos[i])
        {
            mark[i][pos[i]] = k++;
            bit2.set(pos[i]);
            pos[i] = prox[i][pos[i]];
        }
        sz[i] = k;
        bit1 &= bit2;
    }
    int f = 0;
    for(int i = M; i >= 1; i--)
    {
        if(bit1[i] && solve(i))
        {
            f = 1;
            if(atual <= best)
            {
                best = atual;
                bestid = i;
            }
        }
    }
    if(f)
        printf("%d %llu\n", bestid, best+val);
    else
        printf("*\n");
    return 0;
}
