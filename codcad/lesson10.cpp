#include <bits/stdc++.h>

using namespace std;

int main()
{
    char oper;
    double a, b;

    cin>>oper;
    cin>>a>>b;

    cout.precision(2);
    cout.setf(ios::fixed);
    if(oper == 'M')
    {
        cout<<a*b<<endl;
    }else{
        cout<<a/b<<endl;
    }
}
