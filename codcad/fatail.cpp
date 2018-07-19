#include <bits/stdc++.h>

using namespace std;


unsigned int fatorialTR (unsigned int n, unsigned base);

int main()
{
    int n;

    cin>>n;

    n = fatorialTR(n, 1);

    cout<<n<<endl;
}

unsigned int fatorialTR (unsigned int n, unsigned base)
{
    if (n==0) return base;
    return fatorialTR(n-1, n*base);
}


