#include<bits/stdc++.h>
using namespace std;

int TC;          
char board[4];

bool place(int r, int c)
{
    for(int prevr = 0; prevr <= r; prevr++) 
        for(int prevc = 0; prevc <= c; prevc++)
            if(board[prevr][prevc] == 'A' 
            return false;      
    return true;
}

void backtrack(int row, int col)
{
    
    for (int r = 0; r < row; r++) 
        for(int c = 0; c < col; c++)
            if(place(r, c))    
            {
                row[r][c] = 'A';
                if(row < 4) backtrack(row + 1, col);
                else backtrakc(row, col + 1);
            }   
}   

int main()
{
    scanf("%d", &TC);
    while (TC)
    {   
        for(int i = 0; i < TL; i++)
            for(int j = 0; j < TL; j++)
                scanf("%c", &board[i][j];    
        
        backtrack(0, 0); 
        scanf("%d", &TC);
        if (TC) printf("\n");
    } 
} 
