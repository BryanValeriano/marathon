#include <bits/stdc++.h>
using namespace std;

int main()
{
    string hexa;
    cin >> hexa;
    int resultado[255];  

    for(int i = 0; i != hexa.length(); i++)
    {
        if(hexa[i] <= '9') resultado[i] = hexa[i] - 48;
        else resultado[i] = hexa[i] - 97 + 9 ;
    }
    
    for(int i = hexa.length(); i > 0; i--)
    {
        cout << resultado[i];
    }
    
    cout << endl;

     /*
    int n = ;

    printf("%x", n);
    */

    return 0;
}
