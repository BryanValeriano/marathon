#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define MAXN 13

typedef long long ll;

int a, b, linecont, row[MAXN];

bool place(int linha, int coluna)
{
    for(int prev = 0; prev < coluna; prev++)
        if(row[prev] == linha || (abs(row[prev] - linha) == abs(prev - coluna)))
            return false;
    return true;
}


int backtrack(int coluna)
{
    if(coluna == MAXN && row[b] == a)
    {
        cout << setw(3) << linecont << "     ";
        for(int i = 0; i < MAXN; i++) cout << " " << row[i] + 1;
        cout << endl;
        linecont++;
    }

    for(int i = 0; i < MAXN; i++)
    {
        if(place(i, coluna))
        {
            row[coluna] = i;
            backtrack(coluna + 1);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    while(N > 0)
    {
        N--;
        linecont = 1;
        cin >> a >> b;
        a--; b--;
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;

        clock_t begin = clock();
        backtrack(0);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << "tempo: " << elapsed_secs << endl;
        if(N) cout << endl;
    }
    
    return 0;
}

