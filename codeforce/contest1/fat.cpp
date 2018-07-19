#include <bits/stdc++.h>

using namespace std;

unsigned long long int fatail(unsigned long long int, unsigned long long int, unsigned long long int);
unsigned long long int lastdig(unsigned long long int, unsigned long long int);

int main()
{
    unsigned long long int a, b;
    cin >> a >> b;
    

    unsigned long long int n = lastdig(b, a);

    while(n > 10)
    {
        n = n%10;
    }

    cout << n;
    
}

unsigned long long int lastdig(unsigned long long int b, unsigned long long int a)
{
    if(a == b) return 1;
    else if ((b -a) >= 5) return 0;
    else return fatail(b, a, 1);
}

unsigned long long int fatail(unsigned long long int b, unsigned long long int a, unsigned long long int base)
{
    if(b == a) return base % 10;   
    return fatail(b - 1, a, ((b * (base % 10)) %10));
}
