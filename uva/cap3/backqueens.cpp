#include<bits/stdc++.h>
using namespace std;

int TC, minn;
int row[8];
int base[8];

bool place(int r, int c)
{
    for (int prev = 0; prev < c; prev++)  
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return false;   
    return true;
}

void dist()
{
    int tmp = 0;
    for(int i = 0; i < 8; i++)
        if(row[i] != base[i])
            tmp++;
    if(tmp < minn)
    {
        minn = tmp;
    }
}

void backtrack(int c)
{
  
    if(c == 8) dist();
        
    for(int r = 0; r < 8; r++)  
        if(place(r, c))     
        {
            row[c] = r;
            backtrack(c + 1); 
        }     
}   

int main()
{
    int line = 0;

    while (cin >> base[0])
    {   
        base[0] = base[0] - 1;
        for(int i = 1; i < 8; i++)
        {
            cin >> base[i];
            base[i] = base[i] - 1;
        }
        minn = 8;
        line++;
        memset(row, 0, sizeof row); 
        backtrack(0); 
        printf("Case %d: %d\n", line, minn);
        
    } 
}
