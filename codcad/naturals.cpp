#include <bits/stdc++.h>

using namespace std;


unsigned int naturals (unsigned int n, unsigned base);

int main()
{
    int n;

    cin>>n;

    n = naturals(n, 1);

    cout<<n<<endl;
}

unsigned int naturals (unsigned int n, unsigned base)
{
    if (n==1) return base;
    return naturals(n-1, n+base);
}


