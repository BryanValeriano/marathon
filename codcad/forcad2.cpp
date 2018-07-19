#include <bits/stdc++.h>

using namespace std;

int main ()
{

    int time = 0;   
    int num;
    int cont;
    int ultimo;
   
    cin >> cont;

    cin >> num;
    ultimo = num;
    time += 10;

    for(int i = 1; i < cont; i++)
    { 
        cin >> num;
        if(num - ultimo < 10)
        {
            time += num - ultimo;
        }
        else if(i == cont - 1)
        {
            time += 10;
        }
        else
        {
            time += 10;
        }
        ultimo = num;
    }
    cout << time << endl;
}        

