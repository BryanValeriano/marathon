#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 


bool isdif(int x, int y)
{
    int difx[5];
    int dify[5];
    int k = 0;
    for(int i = 0; i < 5; i++)
    {
        difx[k] = x%10;
        dify[k] = y%10;
        x = x/10;
        y = y/10;
        k++;
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if((i != j && (difx[i] == difx[j] 
            || dify[i] == dify[j])) || difx[i] == dify[j]) return false;
        }
        
    }
    return true;
}
    


int main(){
    ios_base::sync_with_stdio(false);

    int N;
    int sinal = 0;
    int a = 0;
    cin >> N;

    
    while( N != 0)
    {
        sinal = 0;
        for(int i = 1234; i*N < 98765; i++)
        {
            a = i * N;
            if(isdif(a, i))
            {
                if(a < 10000) cout << "0" << a << " / ";
                else cout << a << " / ";
                if(i < 10000) cout << "0" << i << " = " << N << endl;
                else cout << i << " = " << N << endl;
                sinal = 1;
            }
        }

        if(sinal == 0) cout << "There are no solutions for " << N << "." << endl; 
        cin >> N;
        if(N) cout << endl;
    }
        
    
    return 0;
}

