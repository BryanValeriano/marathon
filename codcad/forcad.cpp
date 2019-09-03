#include <bits/stdc++.h>

using namespace std;

int main ()
{

    int time = 0;   
    int num;
    int cont;
    int inicial;
   
    cin >> cont;
    cin >> num;
    inicial = num;

    for(int i = 1; i < cont; i++)
    { 
       cin >> num; 
    }
    time = num - inicial + 10;
    cout << time << endl;
}        

