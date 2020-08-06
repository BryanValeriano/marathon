#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    int total = 0;

    cin>>size;    

    char tipo[size]; 
    cin>>tipo;

    for(int i = 0; i < size; i++)
    {
        switch(tipo[i])
        {
            case'P':
                total += 2;
                break;
            case'C':
                total += 2;
                break;
            case 'A':
                total += 1;
                break;
            default:
                break;
        }
    }
    
    cout<<total<<endl;

    return 0;           
}
