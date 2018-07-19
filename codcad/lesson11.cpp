#include <bits/stdc++.h>

using namespace std;

int main()
{
    int max;
    char oper;
    double a, b;

    cin>>max;
    cin>>a>>oper>>b;

    if(oper == '*')
    {
        if(a * b > max)
        {
            cout<<"OVERFLOW"<<endl;
        }else{
            cout<<"OK"<<endl;
        }
    }else{
        if(a + b > max)
        {
            cout<<"OVERFLOW"<<endl;
        }else{
            cout<<"OK"<<endl;
        }    
    }
}
